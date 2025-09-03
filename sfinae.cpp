#include <iostream>
#include <vector>
#include <type_traits>
//普通函数重载 通过接受参数不同重载
//process string type data
void process(const std::string& value)
{
    std::cout<<"process data is "<< value<<"\n";
}
//process int type data
void process(int  value)
{
    std::cout<<"process data is "<<value<<"\n";
}

//通用模板函数

template<typename T>
void process1(T value)
{
    std::cout<<"处理任何的数据类型 " << value <<"\n";
}
void process1(std::string& value)
{
    std::cout<<"字符串类型特殊处理"<<value<<"\n";
}
//要求传入的类型必须要有size()函数.
template<typename Container>
void process2(Container& vec){
  //这里访问了传入参数的成员函数
    std::cout<<"容器大小"<< vec.size() << std::endl;
}

//只有容器类型才能使用这个函数
template<typename Container>
void process3(Container& c){
    std::cout<<"容器大小"<<c.size()<<"\n";
}
//数组版本
template<typename Array,std::size_t N>
void process3(Array(& arr)[N]){//?
    std::cout<< "数组的大小"<<N<<"\n";
}


int main()
{
    {
        std::vector<int> v1 = {1,2,3,4,5};
        int arr[] = {1,2,3,4,5};
        process3(v1);//走进容器类型
        process3(arr);//走进数组类型
        
    }
    {process(19);//参数匹配int的函数
    process("My name is guodong");//参数匹配string的函数
    process(3.14121212);//这里找不到匹配的参数 把double隐饰转换成int类型了
    }

    {
        process1(182);
        process1(1.1221);
        process1('c');
        process1("I want to become engineer!\n");//这里是一个又值传入并非引用
        std::string name("guodong");
        process1(name);//name名字就是地址 所以这里匹配的是引用传递函数
    }

    {
        //process2(10);//找不到函数定义
        std::vector v={1,2,3,4,5};
        process2(v);
        //int arr[] = {1,2,3,4,5};
        //process2(arr);报错 因为int类型数组没有size()成员
    }
    return 0;
}