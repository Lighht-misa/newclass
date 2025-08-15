#include "SimpleShareptr.h"
#include "Student.h"
#include <iostream>
#include <thread>
int main()
{
	std::cout << "Creating default construct shared_ptr..." << "\n";
	SimpleShareptr<Student> s1;
	std::cout << "s1's use_count: " << s1.use_count() << "\n";

	std::cout << "Creating default construct shared_ptr..." << "\n";
	SimpleShareptr<Student> s2(new Student());
	std::cout << "successed\n";
	std::cout << "s1's use_count: " << s2.use_count() << "\n";

	std::cout << "s2's name is : " << s2->getname()<< "\n";
	s2->setname("gd");
	std::cout << "s2's name is : " << s2->getname() << "\n";

	std::thread t1([s2]() {
		s2->setname("feihu");
		});
	std::cout << "s2's name is : " << s2->getname() << "\n";
	t1.join();
	return 0;
}