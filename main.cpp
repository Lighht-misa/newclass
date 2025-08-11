#include <iostream>
#include "Student.h"
int main()
{
	Student s1("gd",1,18);
	std::cout << "s1's name :" << s1.getname() << " ";
	std::cout << "s1's num : " << s1.getage() << " ";
	std::cout << "s1's age : " << s1.getnum() << " ";
}