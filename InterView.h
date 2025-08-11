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
	//delete�ؼ��ֵ�����������Ҫ��ϵͳ����Ĭ�Ϲ���
	DefaultClass(const DefaultClass& s) = delete;
	DefaultClass& operator=(const DefaultClass& S) = delete;
	//�����಻��ʵ�ֿ���������ǵ���ģʽ
	friend std::ostream& operator<<(std::ostream& out, const DefaultClass& defaultclass);
private:
	int num1;
};