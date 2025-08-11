#include "memory.h"
#include <cstdio>
int main() {
	Student* s1 = (Student*)malloc(sizeof(Student));//malloc不能调用构造函数
	std::cout << "S1's age is :" << s1->age << "\n";//doesn't init
	free(s1);
	Student s2;
	std::cout << "S2's age is :" << s2.age << " and the name is:" << s2.name << "\n";
	Student* s3 = new Student;//new 可以会自动调用构造函数
	std::cout << "S3's age is :" << s3->age << " and the name is:" << s3->name << "\n";
	auto s4 = new Student[2]{ {"laohu",19},{} };
	std::cout << s4[0].age << s4[0].name << std::endl;
	std::cout << s4[1].age << s4[1].name << std::endl;
	delete[] s4;

	int* aptr = (int*)malloc(sizeof(int) * 3);
		for (int i = 0; i < 3; i++)
	{
			aptr[i] = i * 2;
		}
		std::cout << aptr[0];
		std::cout << aptr[1];
		std::cout << aptr[2];

		aptr = (int *)realloc(aptr, sizeof(int) * 5);
		for (int i = 0; i!=5; i++)
		{
			std::cout << aptr[i] << "\n";
		}
		std::cout << "\n";
		free(aptr);
		return 0;
	}
