#include <iostream>
#include <utility>
class Data{
    public:
    Data(){std::cout<<"默认构造\n";}
    Data(const Data&){std::cout<<"拷贝构造\n";}
    Data(Data&&value){std::cout<<"移动构造\n";}
};  
void process(Data&){std::cout<<"处理左值\n";}
void process(Data&&){std::cout<<"处理右值\n";}

//普通转发函数
void relay_normal(Data data)
{
    process(data);
}
template<typename T>
void relay_perfect(T&& data)
{
    process(std::forward<T>(data));
}
int main(){
    Data d1;
    relay_normal(d1);
    relay_normal(Data());

     Data d2;
    relay_perfect(d2);
    relay_perfect(Data());
    
    return 0;
}