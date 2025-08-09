#include <iostream>
#include <vector>

std::vector<int> finbonacci(int n)
{
    std::vector<int> fin(n);
    fin[0] = 0;
    if(n > 1)
    {   
        fin[1] = 1;
    }
    for(int i =2;i<n;i++)
    {
        fin[i] = fin[i-1] + fin[i-2];
    }
    return fin;
}


    int fbnq(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        return fbnq(n -1) + fbnq(n -2);
    }
int main(){
    std::cout<<"请选择要生成斐波那契个数：\n";
    int num;
    std::cin>>num;
    if(num < 0)
    {
        return 0;
    }
    int arr[num];
    for(int i =0;i<num;i++)
    {
        arr[i] = fbnq(i);
    }
        
   
    for(int i =0;i <num ;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}