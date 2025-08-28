#include <iostream>

void log(const std::string& s)
{
    std::cout<<s<<"\n";
}
template<typename T,typename... Args>
void log(const std::string &msg,const T& first,const Args&... args){
    std::cout<<msg<<":"<<first<<" ";
    log(" ",args...);
}