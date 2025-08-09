#include <iostream>
#include <vector>
#include <algorithm>
int main(){ 
    std::vector<int> v1={4,2,52,12,435,334,5};
    std::sort(v1.begin(),v1.end());
    for(auto i : v1)
    {
        std::cout<< i <<" ";
    }
    std::cout<<" \n";
}