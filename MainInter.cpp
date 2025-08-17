#include "Student.h"
#include <iostream>
#include <memory>
#include <cstdio>
int main() {
	//First write
	//auto* student = new Student();
	//std::shared_ptr<Student>shared_student1(student);
	//Second write
	//移动构造
	//std::shared_ptr<Student>shared_student2 = std::shared_ptr<Student>(student);
	//直接new一个新的对象并且指向它
	std::shared_ptr<Student>Shared_student3(new Student("gd", 19));
	//通过make_shared函数构造了一个Student赋值给Shard student4 =make出来的为一个右值
	std::shared_ptr<Student>shared_student4 = std::make_shared<Student>("geihu", 20);
	//调用拷贝构造共享一个对象 引用计数加一
	std::shared_ptr<Student>shared_student5 = shared_student4;
	std::cout << "shared_student's use count is " << shared_student5.use_count()<<"\n";
	std::shared_ptr<Student>s1;
	s1 = shared_student5;
	std::cout << "shared_student's use count is " << shared_student5.use_count() << "\n";
	s1.reset(new Student());
	std::cout << "shared_student's use count is " << shared_student5.use_count() << "\n";
	std::cout << s1->getname()<<"\n";

	std::unique_ptr<Student>ptr1(new Student());
	std::cout<<ptr1->getname()<<"\n";

	std::unique_ptr<Student>ptr2 = std::move(ptr1);
	{
		std::shared_ptr<A> ptra = std::make_shared<A>();
		std::shared_ptr<B> ptrb = std::make_shared<B>();
		ptra->ptrb = ptrb;
		ptrb->ptra = ptra;
	}



	struct FileDeleter
	{
		void operator()(FILE* fp) {
			std::cout << "close file\n";
			fclose(fp);
		}
	};
	FileDeleter f1;
	std::shared_ptr<FILE> fileptr(fopen("text.txt", "w"), FileDeleter());
	if (fileptr)
	{
		std::cout << "File opened successfully.\n";
		fprintf(fileptr.get(), "Hello world!\n");
	}
}