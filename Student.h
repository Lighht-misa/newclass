#pragma once
#include <iostream>
class Student
{
private:
	std::string name;
	int age;
public:
	Student();
	void setname(const std::string& S);
	std::string getname();
};

