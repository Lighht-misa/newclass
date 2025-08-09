#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct Student
{
    int age;
    int number;
    std::string name;
};
int main()
{
std::vector<Student> student1;
student1.push_back({18,1,"boro"});
    for(auto &student :student1)
    {
        std::cout<<"Student's name: "<<student.name<<"\nStudent's age:"<<student.age<<"\nStudent's number:"<<student.number<<std::endl;
    }


    std::vector<int> numbers={10,20,22,1,2,3,4,4,67,9,53,8,6,314,12031,1231231};
    for(auto &bumber:numbers)
    {
        std::cout<<bumber<<"  ";
    }
    std::cout<<std::endl;
    std::sort(numbers.begin(),numbers.end());
    for(auto &bumber:numbers)
    {
        std::cout<<bumber<<"  ";
    }
    std::cout<<std::endl;
    {
        std::vector<int> number;
        number.reserve(100);
        for(int i =0;i<100;i++)
        {
            number.push_back(i);
        }
        
        for(auto &i :number)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"number capacity:"<<number.capacity()<<"\n";
    }
}