#include <iostream>
#include <type_traits>
#include <concepts>
template<typename T>
concept Integral = std::is_same_t<T,st::string>;
int main(){
    return 0;   
}