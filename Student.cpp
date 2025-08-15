#include "Student.h"
Student::Student() :name("laohu"), age(18) {}
void Student::setname(const std::string& S) {
	this->name = S;
}
std::string Student::getname() {
	return name;
}