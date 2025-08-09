#include <iostream>
#include <vector>

int main()
{  
    int num=1;
    std::vector<int> v1;
    while(num != 5 )
    {
        v1.push_back(num);
        num++;
        
    }


    for(auto it1 :v1)
    {
        std::cout<<it1<<" ";
    }
    std::cout<<std::endl;



    int num1=1;
    std::vector<int> v2 = {5,6,7,8,9,10};



    for(auto it1 :v2)
    {
        std::cout<<it1<<" ";
    }
    std::cout<<std::endl;

    for(auto itv2 = v2.begin();itv2!=v2.end();itv2++)
    {
        v1.push_back(*itv2);
    }
    for(auto a : v1)
    {
        std::cout<<a<<" ";
    }

   /* for(auto it = v1.rbegin();it!=v1.rend();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
   /* for(auto it3 = v1.begin();it3 +1!=v1.end();it3++)
    {
        std::cout<<*it3 + (*it3 +1)<<" ";
    }
    std::cout<<std::endl;*/
}