#include <iostream>
#include <vector>
#include <type_traits>

//SFINAE特性
//std::enable_if<>实现函数重载
//用于处理int，folat等数据类型、
template<typename T>
//enable_if(1,2)这个函数决定了 是否启用这个函数模板 当条件不满足的时候，该模板实例化失败 但是编译器不会报错 而是忽略这个模板
//因为里面跟的是is int函数 所以会判断这个t类型是不是int 不是就退出这个函数
typename std::enable_if<std::is_integral<T>::value,void>::type
print_type(T value){
    std::cout<<"Intergal type "<< value <<"\n";
}

//因为里面跟的是is string函数 所以会判断这个t类型是不是float 不是就退出这个函数
template<typename T>
typename std::enable_if<std::is_floating_point<T>::value,void>::type//如果第一个为ture的话type就等于void

print_type(T value){
    std::cout<<"float type "<< value <<"\n";
}
//process else data type
template<typename T>
typename std::enable_if<
    std::is_same<T,std::string>::value,void
>::type
print_type(T value){
    std::cout<<"Process string data type "<<value<<"\n";
}
//c风格字符串
template<typename T>//std::is_same<1,2>::value 这个函数检测1和2是否是相同类型数据 如果是返回value返回ture
typename std::enable_if<std::is_same<T,const char*>::value,void>::type
print_type(T c)
{
    std::cout<<"porcess Char type" << c<<"\n";
}
int main(){
    print_type(199);//走进int
    print_type(19.9);//走进float
    std::string str = "guodong!";
    print_type(str);//走进其他的数据类型
    const char* cstr = "Hello world";
    print_type(cstr);
    return 0;
}