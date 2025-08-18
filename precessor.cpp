#include "precessor.h"
#include <iostream>
processor::processor(int Value):_threshold(Value)
{

}

void processor::process(std::vector<int>& v)
{
	std::cout << "Before process data:";
	for (auto num : v)
	{
		std::cout << num << " ";
	}
	std::cout << "\n";
	auto new_end = std::remove_if(v.begin(), v.end(), [this](int n) {
		return n < _threshold;
		});
	v.erase(new_end, v.end());
	std::cout << "After process data:";
	for (auto& i : v)std::cout << i << " ";
	std::cout << "\n";
}
