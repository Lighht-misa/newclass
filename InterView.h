#pragma once
#include <iostream>

class innnerB{
public:
	innnerB() {
		std::cout << "Inner()"<<std::endl;
	}
	~innnerB() {
		std::cout << "~Inner()" << "\n";
	}
};

class WrapperC :public innnerB{
public:
	WrapperC() {
		std::cout << "Wrapper()\n";
}
	~WrapperC() {
		std::cout << "~WrapperC()\n";
}
};


class DefaultClass {
public:
	DefaultClass() = default;
	//delete关键字的析构函数是要求系统生成默认构造
	DefaultClass(const DefaultClass& s) = delete;
	DefaultClass& operator=(const DefaultClass& S) = delete;
	//声明类不能实现拷贝构造就是单例模式
	friend std::ostream& operator<<(std::ostream& out, const DefaultClass& defaultclass);
private:
	int num1;
};