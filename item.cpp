#include<iostream>
#include <vector>
#include <string>


int main(){
    {
        std::string s1 ="hello from guoddong";
        if(s1.begin()!=s1.end())
        {
            auto iter = s1.begin();
            *iter = toupper(*iter);
            std::cout<<s1<<std::endl;
        }
    }

    {
        std::string str = "another string ";
        for(auto item = str.begin();item != str.end() && !isspace(*item);++item)
        {
            *item = toupper(*item);
        }
          std::cout<<str<<std::endl;
     }

     {
        std::vector<int>::const_iterator cit;
        std::vector<int> v1={1,2,3,4,5,6};
        //常量的迭代器不能对指向的对象操作数据 
        //*cit = 100;
        for(cit=v1.begin();cit!=v1.end();cit++)
        {
            std::cout<<*cit;
        }    
        std::cout<<"\n";
    }

    {
        std::vector<std::string> s1 = {"hello","world"};
        auto s1item = s1.begin();
        if(s1.begin() != s1.end())
        {
            if(s1item->empty())
            {
                std::cout<<" empty !\n";
            }else{
                std::cout<<"not empty\n";
            }
        }
    }

    {
        std::vector<std::string> s1 = {"hello","","world"};
        std::vector<std::string>::iterator it1;
        if(s1.begin()!= s1.end())
        {
            for(it1 = s1.begin();it1!= s1.end() && ! it1->empty(); it1++)
            {
                std::cout<<*it1;
            }
            std::cout<<std::endl;
        }
    }

    {
        /*std::vector<int> s1 = {10,2,2,2,2};
        for(auto it1 = s1.begin();it1!=s1.end();it1++)
        {
            std::cout<<*it1;
            s1.push_back(*it1);
            std::cout<<std::endl;
        }
            */
    }

    {
        std::vector<int> v1={1,2,3,4,5,6,7,8,9,10};
        for(std::vector<int>::iterator it = v1.begin();it!= v1.end();)
        {
            if(*it % 2 != 0 )
            {
                it  = v1.erase(it);
            }else{
                it++;
            }
        }

        for(auto int1: v1)
        {
            std::cout<<int1<<std::endl;
        }
    }

    {
        std::vector<int> v1={1,2,3,4,5,6,7,8,9,10};
        auto it1 = v1.begin() + v1.size()/2;
        std::cout<<*it1;
    }

    {
        
    }
}