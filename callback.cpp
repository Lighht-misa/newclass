#include <iostream>
typedef void (*callback)();

void registerCallback(callback cb)
{
    std::cout<<"Before callback "<<" \n";
    cb();
    std::cout<<"After callback "<<"\n";
}
void mycallback()
{
    std::cout<<"my Call back \n";
}
int main(){
    registerCallback(mycallback);
}