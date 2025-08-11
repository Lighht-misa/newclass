#include <iostream>
#include <string>
#include<thread>
class Student {
public:
	Student();
	Student(const std::string& s, const int& num, const int& age);
	Student(const Student&s);
	Student(Student&& s);
	~Student();
	std::string getname();
	int getnum();
	int getage();

	static void Textstatic();

	Student& operator=(const Student& s);
private:
	int* _data = new int();
	std::thread _thread;
	std::string _name;
	int* data;
	int _num;
	int _age;
	static int _money;
};