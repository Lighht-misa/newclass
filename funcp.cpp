#include <iostream>
void greet()
{
    std::cout<<"hello from greet!.\n";
}
void execute(void(*func)())
{
    func();
}
int main()
{
    void(*funcp)() = greet;
    funcp();
    execute(greet);
}