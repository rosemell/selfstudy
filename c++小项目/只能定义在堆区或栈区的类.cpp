#define _CRT_SECURE_NO_WARNINGS 1
//����һ���࣬�������ֻ�ܴ����ڶ�������ջ����������̬��
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