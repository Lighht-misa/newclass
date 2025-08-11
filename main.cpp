#include "InterView.h"
#include <iostream>
class Myclass {
private:
	int value;
public:
	Myclass& setValue(int value)
	{
		this->value = value;
		return *this;
	}
};


int main() {
	innnerB n1;
	WrapperC w1;
	Myclass Obeject;
	DefaultClass d,c,e,f;
	std::cout << d<<c<<e<<f;
}