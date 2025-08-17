#include "Student.h"
#include <iostream>
#include <memory>
#include <cstdio>
int main() {
	//First write
	//auto* student = new Student();
	//std::shared_ptr<Student>shared_student1(student);
	//Second write
	//�ƶ�����
	//std::shared_ptr<Student>shared_student2 = std::shared_ptr<Student>(student);
	//ֱ��newһ���µĶ�����ָ����
	std::shared_ptr<Student>Shared_student3(new Student("gd", 19));
	//ͨ��make_shared����������һ��Student��ֵ��Shard student4 =make������Ϊһ����ֵ
	std::shared_ptr<Student>shared_student4 = std::make_shared<Student>("geihu", 20);
	//���ÿ������칲��һ������ ���ü�����һ
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