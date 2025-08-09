#include <iostream>


int main()
{
    int n;
    std::cout<<"请输入数组的大小:\n";
    std::cin>>n;
    int arr[n];
    for(int i =0;i!= n;i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"排序前数组顺序：\n";
    for(int i =0;i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"交换后的元素排序：\n";
    for(int i =0;i< sizeof(arr) / sizeof(int);i++)
    {
        for(int j =0; j <n- i -1 ; j++)
        {
            int temp;
        if(arr[j] > arr[j+1])
        {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
         }
        }
        
    }
    for(int i =0;i!=n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}