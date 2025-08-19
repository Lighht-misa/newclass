#include <iostream>
#include <vector>
#include <functional>
struct Multiply
{
	int operator()(int x, int y) {
		return x * y;
	}
};
int add(int x, int y)
{
	return x + y;
}
//定义回调类型
using  callback = std::function<void(int)>;
//触发事件的函数
void TriggerEvent(callback cb, int value) {
//触发事件调用回调函数
	cb(value);
}
void Printf(int a,int b,int c) {
	std::cout << a << " " << b << " " << c << "\n";
}
class Calculator {
public:
	
	Calculator() :result(0){}
	int add(int a, int b)
	{
		std::cout << a + b<<"\n";
		return a + b;
	}
	int result;
};
class greeter {
public:
	void greet(const std::string&name) {
		std::cout << "Hello "<<name << "!\n";
	}
};
class Logger {
public:
	static std::string message;
	static void PrintLog(const std::string& message1)
	{
		message = message1;
		std::cout << message << "\n";
	}
};
std::string Logger::message;
class Math {
public:
	double power(double base,double exponst) {
		double resule = 1;
		for (int i = 0; i < static_cast<int>(exponst);i++)
		{
			resule *= base;
		}
		return resule;
	}
};
int main() {
	{
		Math m;
		auto Mathfun = std::bind(&Math::power,&m, 2.0, std::placeholders::_1);
		std::cout<<Mathfun(5)<<"\n";
		auto Mathfun2 = [&m](const double &value) {
			return m.power(2,value);
			 
			};
		std::cout<<Mathfun2(5)<<"\n";

		auto logfunc = std::bind(&Logger::PrintLog, std::placeholders::_1);
		logfunc("This is a new message");
		auto logfunc2 = [](const std::string&message ) {
			Logger::PrintLog(message);
			};
		logfunc2("feihu");
		greeter greet;
		auto new_func4 = [&greet](const std::string& name) {
			greet.greet(name);
			};
		new_func4("guodong");
		//封装函数
		std::function<int(int, int)> func1 = add;
		std::cout << "Add function :" << func1(10, 99) << "\n";
		std::function<int(int, int)>func2 = Multiply();
		std::cout << "Func2 :" << func2(10, 99) << "\n";
		std::function<int(int, int)>func3 = [](int x, int y) {return x - y; };
		std::cout << "Sbutrck:" << func3(10, 99) << "\n";
	}
	TriggerEvent([](int a) {
		std::cout << "事件触发值为：" << a << "\n";
		}, 10);
	struct Printer
	{
		int operator()(int x) { std::cout << "Printer 调用 ，值为：" << x << "\n"; return x;	 }
	};
	TriggerEvent(Printer(), 99);
	std::vector<std::function<int(int, int)>> operations;
	operations.emplace_back(add);
	operations.emplace_back(Multiply());
	operations.emplace_back([](int x, int y) {
		return x - y;
		});
	for (auto& it : operations)
	{
		std::cout << it(100, 99) << "\n";
	}
	auto new_add = std::bind(add, 10, std::placeholders::_1);
	std::cout << new_add(999) << "\n";

	auto new_printf = std::bind(Printf, 
						std::placeholders::_3, 
						std::placeholders::_2,
						std::placeholders::_1);
	new_printf(1, 2, 3);
	Calculator ca;
	auto new_func = std::bind(&Calculator::add, &ca, 9999999, std::placeholders::_1);
	new_func(1);
	auto new_func2 = [&ca](int x) {
		ca.add(9999999, x);
		};
	new_func2(-9);
}