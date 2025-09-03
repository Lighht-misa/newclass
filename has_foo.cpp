#include <iostream>
#include <type_traits>

template<typename T>
class has_foo{
private:
    typedef char yes[1];//定义一个拥有一个字符的字符数组 类型名为yes
    typedef char no[2];//定义一个拥有两个字符数组的类型 名称为no

    template<typename U,void(U::*)()>//当实例化一个SFINAE的时候，要求传入一个数据类型U 和一个void类型的函数指针
    struct SFINAE{};

    template<typename U>
    static yes& test(SFINAE<U,&U::foo>*);//运行时会查找U下面的成员函数foo的地址
    

    template<typename U>
    static no& test(...);
    
    public:
    static constexpr bool value=sizeof(test<T>(0)) == sizeof(yes);
};
template<typename T>
typename std::enable_if<has_foo<T>::value,void>::type
    call_foo(T &obj){
    obj.foo();std::cout<<"foo called()\n";
};
class withoutfoo{};
class Withfoo{
    public:
    void foo(){
        std::cout<<"Foo()\n"<<std::endl;
    }
};
int main(){
    Withfoo wf1;
    call_foo(wf1);
    withoutfoo wf2;
    //call_foo(wf2);
    return 0;
}