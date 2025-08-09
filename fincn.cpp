#include <iostream>
#include <vector>
int fincbic(int n )
{
    if(n ==0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fincbic(n-1) + fincbic(n - 2);
}
int main(){
std::cout<<"请输入项数: \n";
int n ;
std::cin>>n;
int result = fincbic(n);
std::cout<<"第"<<n<<"项的数为："<<result<<"\n";


std::cout<<"请输入要查看的个数：\n";
int sum;
std::cin>>sum;
std::vector<int> v1;
for(int i =0;i<=sum;i++)
{
    v1.push_back(fincbic(i));
}

std::cout<<"\n";
for(auto i  : v1)
{
    std::cout<<i<<" ";
}

std::cout<< " \n";
}