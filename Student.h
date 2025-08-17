#pragma once
#include <iostream>
#include <memory>
#include <cstdio>

class Student
{
public:
	Student();
	Student(const Student& s);
	Student(std::string name, int age);
	std::string getname();
	int getage();
private:
	std::string name;
	int age;
};

class B;
class A {
public:
	std::shared_ptr<B>ptrb;

	A() {
		std::cout << "A()" << "\n";
	}
	~A() {
		std::cout << "~A()" << "\n";
	}
};
class B {
public:
	std::weak_ptr<A>ptra;
	B() {
		std::cout << "B()" << "\n";
	}
	~B() {
		std::cout << "~B()" << "\n";
	}
};
