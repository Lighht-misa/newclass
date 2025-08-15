#pragma once
#include <iostream>
class DynameicArray {
public:
	DynameicArray():capacity(2),size(0),data((int*)malloc(capacity*sizeof(int)))
	{
		if (data == nullptr)
		{
			std::cerr << "malloc fali\n";
			throw std::bad_alloc{};
		}
	}
	~DynameicArray() {
		free(data);
	}
	void add(int value)
	{
		if (size == capacity)
		{
			resize(capacity * 2);
		}
		data[size++] = value;
	}
	int  getcapacity() {
		return capacity;
	}
	int getindex(size_t index)
	{
		if (index > size)
		{
			throw std::out_of_range{"index out of range"};
		}
		return data[index];
	}

	size_t getsize() const{
		return size;
	}
private:
	void resize(size_t new_capacity)
	{
		int* temp = (int*)realloc(data, new_capacity * sizeof(int));
		if (temp == nullptr)
		{
			throw std::bad_alloc{};
		}
		data = temp;
		capacity = new_capacity;
	}
	size_t capacity;
	size_t size;
	int* data;
};