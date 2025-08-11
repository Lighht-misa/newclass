#include "Student.h"
int Student::getage()
{
	return this->_age;
}
int Student::getnum()
{
	return this->_num;
}
std::string Student::getname()
{
	return this->_name;
}
Student::Student():_name(""),_age(0),_num(0)
{
	
}

Student::Student(const std::string& s, const int& num, const int& age) :_name(s), _num(num), _age(age){}
Student::Student(const Student&s):_name(s._name),_num(s._num),_age(s._age){}
Student::Student(Student&& s) :_name(std::move(s._name)), _age(std::move(s._age)), _num(std::move(s._num)),_thread(std::move(s._thread))
{}
Student & Student::operator=(const Student& s)
{
	if (this == &s)
	{
		return *this;
	}

	this->_age = s._age;
	this->_name = std::move(s._name);
	this->_num = s._num;
	(*data) = (*s.data);
	return *this;
}
void Student::Textstatic()
{
	std::cout << "This money is " << _money;
}
Student::~Student()
{
	std::cout << "~Sudent() successed" << std::endl;
}
