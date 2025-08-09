#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    std::vector<std::string> s1;
    s1.push_back("banaa");
    s1.push_back("bfwefnaa");
    s1.push_back("ba");
    s1.push_back("ffdsfsfsaanaa");
    s1.push_back("ban434feeeeeeefeeeeeea");
     for(auto &i :s1)
    {
        std::cout<<i<<" ";
    }std::cout<<"\n";
    std::sort(s1.begin(),s1.end(),[](const  std::string &a,const std::string &b)->bool{return  b.length() <a.length();});

    for(auto &i :s1)
    {
        std::cout<<i<<" ";
    }std::cout<<"\n";
}