#include <iostream>
#include <type_traits>
#include <concepts>
template<typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value,void>::type
print_if_numebr(T value)
{
    std::cout<<value<<"\n";
}

template<typename T>
typename std::enable_if<std::is_same<T,const char*>::value || std::is_same<T,const char[]>::value || std::is_same<T,const char>::value,void>::type
print_if_numebr(T value)
{
    std::cout<<"Doing nothing!\n";
}

//创建has_size_method
//辅助类型判断有没有size（）函数
template<typename T>
class has_size_method{
    public:
    bool is();
    bool value;
};
template<typename T>
typename std::enable_if<has_size_method<T>::value>::type
print_size(T & v){
    std::cout<<v.size()<<"\n";
}


template<typename T>
concept Integral = std::is_integral_v<T>;//如果T是int类型 InterGal将会被约束为int类型  等于声明了一个类型 如果成立Inteegral就是一个int类型的数据类型

template<typename T>
concept floatingPoint  =  std::is_floating_point_v<T>;//等于声明一个floatingPoint数据的数据类型  

template<typename T>
concept Cstring = std::is_same_v<T,const char*> || std::is_same_v<T,char*>;

template<typename T>
concept Stdstirng  = std::is_same_v<T,const std::string> || std::is_same_v<T,std::string>;

template<typename T>
concept PointerType = std::is_pointer_v<T> &&  ! std::is_same_v<T,char*> && ! std::is_same_v<T,const char*>;

void couttype(Integral auto value){ // 用auto是因为InterGal是概念不是数据类型 要求编译器通过概念推倒value的类型
    std::cout<<"Intergral  " <<value<<"\n";
}
void couttype(floatingPoint auto value){
    std::cout<<"floatingPoint  "<<value<<"\n";
}
void couttype(Cstring auto value){
    std::cout<<"Cstring  "<<value<<"\n";
}
void couttype(Stdstirng auto value){
    std::cout<<"Stdstirng  "<<value<<"\n";
}

void couttype(PointerType auto value){
    std::cout<<"PointerType  "<<value<<"\n";
}

template<typename T>
requires(! Integral<T> && !floatingPoint<T> && !Cstring<T> && !Stdstirng<T> && !PointerType<T>)
void couttype(T value){
    std::cout<<"Other type  "<<value<<"\n";
}


int main(){
    print_if_numebr(42);
    print_if_numebr(3.14);
    print_if_numebr("hello");


    couttype(100);
    couttype(2.22);
    couttype("guodong");
    const char* arr = "afafa";
    couttype(arr);
    std::string s1 = "feiguo";
    couttype(s1);
    
    return 0;
}