#define _CRT_SECURE_NO_WARNINGS 1
//创建一个类，让这个类只能创建在堆区或者栈区（包括静态区
#include<stdio.h>
#include<iostream>
class Aheap
{
public:
	static Aheap* GetAheap()
	{
		return new Aheap;
	}

private:
	Aheap()
	{
		std::cout<<"Aheap()"<<std::endl;
	}
	int _Aheap;
};
class Astack
{
public:
	Astack()
	{
		std::cout << "Astack()" << std::endl;
	}
private:
	void* operator new(size_t)
	{

	}
	void operator delete(void*)
	{

	}

	int _Astack;
};

int main()
{
	Aheap* pAheapObj = Aheap::GetAheap();
	Astack AstackObj;
	return 0;
}