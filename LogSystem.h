#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <fstream>
#include <atomic>
#include <sstream>
#include <vector>
#include <stdexcept>

//辅助函数:实现将单个参数转换为字符串
template<typename T>
std::string to_string_helper(T&&args){
    std::ostringstream oss;
    oss << std::forward<T>(args);
    return oss.str();
}
//消息队列
class LogQueue{
    public:
        void push(const std::string& msg){
            std::lock_guard<std::mutex> lock(mutex_);//这是一个封装好的加锁的模板类 具有RAII思想 在构造这个类的时候创建一个锁 析构的时候释放这个锁
            queue_.push(msg);//上锁之后就可以往消息队列里面加数据了
            if(queue_.size() == 1)
            {
            cond_var_.notify_one();//告诉消费者可以消费队列了
            }
        }
        bool pop(std::string& msg){
            std::unique_lock<std::mutex> lock(mutex_);//消费者是另外一个线程 也需要进行加锁让线程去竟争
            cond_var_.wait(lock,[this](){
             return !queue_.empty() ||  is_shutdown_;//当消息队列为空的时候返回false 当消息队列为真的时候返回ture lambda只要不返回ture就一直等待
            });//新的判别式 捕获当前的对象 为了访问当前对象的所有成员变量

            /*while(queue_.empty() )//加锁之后进行判断 判断队列是否为空 为了防止虚假唤醒所以用while循环
            {
            cond_var_.wait(lock);//如果消费队列为空就等待
            }
            */
           //消费逻辑
           //is_shutdown是接受主线程关闭的消息 
           if(is_shutdown_ && queue_.empty())//如果已经关闭了 以及队列为空直接返回flase
           {
            return false;
           }
           //如果通过了就取出数据
           msg = queue_.front();
           queue_.pop();
           return true;
        }
        void shutdown(){
            std::lock_guard<std::mutex> lock(mutex_);
            is_shutdown_ = true;
            cond_var_.notify_all(); 
        }
    private:
        std::queue<std::string> queue_;//队列 生产者往里面放数据 消费者从里面取数据
        std::mutex mutex_;//为了保证线程安全 我们声明一个锁保护线程
        std::condition_variable cond_var_;//为了保证同步我们要使用条件变量
        bool is_shutdown_ = false;

};

class Looger{
    public:
        Looger(const std::string & filename):log_file_(filename,std::ios::out | std::ios::app),exit_flag_(false)
        {
            if(!log_file_.is_open())//判断文件是否打开
            {
                throw std::runtime_error("Failed to open log file");
            }   
            //如果文件打开没问题就开始启动线程
            worker_thread_ = std::thread([this]() {
    std::string msg;
    while (true) {
        // 使用pop的返回值控制循环
        if (!log_queue_.pop(msg)) {
            break; // 当pop返回false时退出
        }
        log_file_ << msg << std::endl;
    }
    // 确保刷新缓冲区
    log_file_.flush(); 
});
            
    }
        ~Looger(){
            exit_flag_ = true;
            log_queue_.shutdown();
            if(worker_thread_.joinable())
            {
                worker_thread_.join();
            }
            if(log_file_.is_open())
            {
                log_file_.close();
            }
        }
        template<typename... Args>
        void log(const std::string & format, Args&&... args){
            log_queue_.push(formatMassage(format,std::forward<Args>(args)...));//通过一个函数把字符串拼接
        }
    private:
    template<typename... Args>
    std::string formatMassage(const std::string& format,Args&&... args){
        std::vector<std::string> arg_strings = {to_string_helper(std::forward<Args>(args))...};
        std::ostringstream oss;
        size_t arg_index = 0;
        size_t pos = 0;
        size_t placeholder = format.find("{}",pos);
        while(placeholder != std::string::npos)
        {
            oss << format.substr(pos,placeholder - pos);
            if(arg_index < arg_strings.size()){
            oss << arg_strings[arg_index];
            }else{
                oss << "{}";
            }

            pos = placeholder + 2;
            placeholder  = format.find("{}",pos);
        }
        oss << format.substr(pos);
        while(arg_index < arg_strings.size()){
            oss << arg_strings[arg_index++];
        }
        return oss.str();
    }
    LogQueue log_queue_;
    std::thread worker_thread_;
    std::ofstream log_file_;//往文件中写数据
    std::atomic<bool> exit_flag_;//原子数据记录退出信息 用于通知队列退出
};