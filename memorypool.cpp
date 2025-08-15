#include "memorypool.h"
memorypool::memorypool(size_t objSize, size_t totalSize) :objSize(objSize), totalSize(totalSize) {
	pool = (char*)malloc(objSize * totalSize);
	if (pool = nullptr)
	{
		throw std::bad_alloc(); 
	}
	//≥ı ºªØfreelist
	for (size_t i = 0; i < totalSize; i++)
	{
		freelist.push(pool + i * objSize);
	}

}	
memorypool::~memorypool() {
	free(pool);
}
void* memorypool::allocate() {
	if (freelist.empty())
	{
		throw std::bad_alloc();
		void* p = freelist.top();
		freelist.pop();
		return p;
	}
}
void memorypool::deallocate(void*ptr)
{
	freelist.push(ptr);
}