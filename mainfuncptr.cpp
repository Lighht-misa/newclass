#include "precessor.h"
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <thread>
#include <vector>
//函数指针 
//变量名称的括号可写可以不写
int(*funcptr)(int a, int b);

int add(int a, int b) {


	return a + b;
}
struct adder
{
	int to_add;
	int getValue() { return to_add; }
	adder(int value) :to_add(value){}
	void add(int x)
	{
		to_add + x;
	}
	int operator()(int a) {
		return a + to_add;
	}
};
struct IsGreaterThan
{
	int to_add;
	IsGreaterThan(int value) :to_add(value) {}

	bool operator()(int value) {
		return value > to_add;
	}
};
template <typename T>
struct Compare
{
	bool operator()(const T& F, const T& TO) {
		return F < TO;
	}
};
int main() {
	
		processor ps(5);
		std::vector<int> v = { 1,3,6,8,10 };
		ps.process(v);
	//std::thread t1;
	//{
	//	auto add_ptr = std::make_shared<adder>(100);
	//	auto lambda = [add_ptr](int x) {
	//		std::cout << "Lambda's use_count is " << add_ptr.use_count()<<"\n";
	//		std::this_thread::sleep_for(std::chrono::seconds(10));
	//		add_ptr->add(x);
	//		std::cout << add_ptr.use_count()<<"\n"; 
	//		};
	//	t1 = std::thread(lambda, 5);
	//	std::cout << "Before } use count : " << add_ptr.use_count()<<"\n";
	//}
	//t1.join();

	//return 0;
	//{
	//	int temp = 5;
	//	auto lambuda = [=, &temp](int x) {return temp *= x; };
	//	lambuda(10);
	//	std::cout << temp<<"\n";
	//}
	//{
	//	int threshold = 10;
	//	std::vector<int>v1 = { 1,30,102,2,3,4,120,22 };
	//	auto new_end = std::remove_if(v1.begin(), v1.end(),
	//		[threshold](int n) {
	//			return  n < threshold;
	//		});
	//	for (auto& i : v1) {
	//		std::cout << i << "  ";
	//	}std::cout << "\b\n";
	//	v1.erase(new_end, v1.end());
	//	for (auto& i : v1) {
	//	std:: cout << i << "  ";
	//	}
	//}
	//{
	//	std::cout << "\n"; 
	//	std::vector<double>v1 = { 1.23232,0.2,0.9,0.821,12.3 };
	//	std::sort(v1.begin(), v1.end(),Compare<double>());
	//	for (auto& i : v1)
	//	{
	//		std::cout << i << "\n";
	//	}
	//}
	//{
	//	std::vector<int> v1 = { 1,2,10,100 };

	//	IsGreaterThan greaterthan(10);
	//	auto it = std::find_if(v1.begin(), v1.end(),greaterthan);
	//	if (it != v1.end())
	//	{
	//	std::cout << *it << "\n";
	//	}
	//}
	//adder a1(10);
	////这里的a1是把结构体当作函数使用 也叫做仿函数
	//std::cout << a1(100) << "\n";





	////让funcptr指向了一个名称为add的函数
	////&可写可以不写 因为函数名就等于函数地址
	//funcptr = &add;

	//int result=	funcptr(19, 19);
	////解引用可写可不写 编译器会做优化
	//int result2 = (*funcptr)(19, 19);

	//std::cout << result << "\n";
	//std::cout << result2 << "\n";

}


