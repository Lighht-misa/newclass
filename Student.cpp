#include "Student.h"
#include <iostream>
Student::Student():name("laohu"),age(18){

}
Student::Student(const Student& s):name(s.name),age(s.age){

}
Student::Student(std::string name, int age):name(name),age(age){

}

std::string Student::getname() {
	return name;
}
int Student::getage() {
	return age;
}