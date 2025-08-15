#pragma once
#include <iostream>
#include "Student.h"
struct Control
{
	int count_ref;
	Control():count_ref(1){}
};
template<typename T>
class SimpleShareptr
{
private:
	T* ptr;
	Control* control;
	void release() {
		if (control)
		{
			this->control->count_ref--;
			if (this->control->count_ref == 0)
			{
				delete ptr;
				ptr = nullptr;
				delete control;
				control = nullptr;
			}
		}
	}
public:
	SimpleShareptr():ptr(nullptr),control(nullptr){}
	~SimpleShareptr() {
		release();
	}
	explicit SimpleShareptr(T*p):ptr(p) {
		if (p) {
			control = new Control;
		}
		else {
			control = nullptr;
		}
	}
	SimpleShareptr(const SimpleShareptr& s) :ptr(s.ptr), control(s.control)
	{
		if (control)
		{
			control->count_ref++;
		}
	}
	SimpleShareptr& operator = (const SimpleShareptr& s) {
		if (this != &s)
		{
			release();
			ptr = s.ptr;
			control = s.control;
			if (control)
			{
				control->count_ref++;
			}
		}
		return *this;
	}

	SimpleShareptr(SimpleShareptr&& other)noexcept :ptr(other.ptr), control(other.control){
		other.control = nullptr;
		other.ptr = nullptr;
	}
	SimpleShareptr& operator = (SimpleShareptr && s) noexcept{
		
		if (this!=s)
		{
			release();
			ptr = s.ptr;
			control = s.control;
			s.control = nullptr;
			s.ptr = nullptr;
		}
		return *this;
	}
	void setname(const std::string& s1)
	{
		ptr.name = s1;
	}
	T& operator*() {
		return *ptr;
	}
	T* operator->()const{
		return ptr;
	}
	T* get()
	{
		return ptr;
	}
	int use_count()const {
		return control ? control->count_ref : 0;
	}
	void reset(T* p) {
		release();
		ptr = p;
		if (control)
		{
			control = new Control();
		}
		else {
			control = nullptr;
		}
	}
};

