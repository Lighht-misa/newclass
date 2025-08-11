#include "interView.h"
#include <iostream>
std::ostream& operator << (std::ostream& out, const DefaultClass& defaultclass) {
	std::cout << defaultclass.num1 << "\n";
	return out;
}
