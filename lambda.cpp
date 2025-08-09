#include <iostream>
typedef void(*callback)();

void executecallback(callback c)
{
    c();
}


int main(){
    callback c = [](){
        std::cout<<"lambda call back !\n";
    };
    executecallback(c);
}