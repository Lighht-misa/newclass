#include<iostream>
//通用模板
template<typename T,typename U>
class Pair{
    public:
    T first;
    U second;
    Pair(T a,U b):first(a),second(b){}
    void print()const {
        std::cout<<"This is granal's Pair:"<<first<<second<<"\n";
    }
};
//通用模板
template<typename T>
class Printer{
public:
    void print(const T&value)const{
        std::cout<<"This is granal printer:"<<value<<"\n";
    }
};
//全特化模板
template<>
class Printer<std::string>{
    public:
    void print(std::string obj){
        std::cout<<"String printer:"<< obj<<"\n";
    }
};
//偏特化模板
template<typename T,typename U>
class Pair<T,U*>{
public:
    T first;
    U* second;
    Pair(T a,U *b):first(a),second(b){}
    void print()const{
        std::cout<<"Patrs speacial Pair:"<<first<<","<<*second<<"\n";
    }
};
//普通模板函数。 
template<typename T>
void printValue(const T& boj){
    std::cout<<"General printValue:"<<boj<<"\n";
}
//全特化模板函数 模板函数只允许被全特化
template<>
void printValue<std::string>(const std::string& obj){
    std::cout<<"Specailzed print for std::string"<<obj<<"\n";
}
//无参数的变参模板底层
void printALL(){
    std::cout<<"\n";
}
//变参模板实现  
//用递归实现
template<typename T,typename... Args>
void printALL(const T & first,const Args&... args){
    std::cout<<first<<" ";
    printALL(args...);
}
//折叠表达式  
template<typename... Args>
void printAll(const Args&... args){
    ((std::cout<<args<<" "),...);
    std::cout<<"\n";
}

//折叠表达式  
template<typename...Args>
auto sum(Args... args)->decltype((args+...)) {
    return (args + ...);
}