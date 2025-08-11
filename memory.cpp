#include "memory.h"
#include <iostream>
Student::Student():age(18),name("tirger"){ }
Student::Student(std::string n,int a):name(n),age(a){}