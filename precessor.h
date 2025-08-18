#pragma once
#include <iostream>
#include <vector>
class processor
{
public:
	processor(int Value);
	void process(std::vector<int>& v);
private:
	int _threshold;
};

