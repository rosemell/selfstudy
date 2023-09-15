#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<list>
using namespace std;
#include"list.h"



int main()
{
	wda::list<int>a;
	for (int i = 0; i < 10; ++i)
	{
		a.push_back(i);
	}
	//for (auto e : a)
	//{
	//	cout << e;
	//}
	for (auto it = --a.end(); it != a.end(); --it)
	{
		cout << *it;
	}
	cout << endl;
	a.clear();
	//for (auto e : a)
	//{
	//	cout << e;
	//}
	for (auto it = --a.end(); it != a.end(); --it)
	{
		cout << *it;
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		a.push_front(i);
	}
	//for (auto e : a)
	//{
	//	cout << e;
	//}
	a.pop_back();
	for (auto it = --a.end(); it != a.end(); --it)
	{
		cout << *it;
	}
	cout << endl;
	cout << a.size()<<endl;
	wda::list<int> a1(a);
	//a1 = a;
	for (auto it = --a1.end(); it != a1.end(); --it)
	{
		cout << *it;
	}
	cout << endl;

	return 0;
}
//
//int main()
//{
//	cout << sizeof(std::list<int>);
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a1 = 0, int a2 = 0)
//		:_a1(a1)
//		,_a2(a2)
//	{
//
//	}
//	int _a1;
//	int _a2;
//};
//int main()
//{
//	wda::list<A>a1;
//	a1.push_back(A(1, 1));
//	auto it = a1.begin();
//	cout << it->_a1;
//	return 0;
//}

//
//int main()
//{
//	wda::list<int>a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	a.push_back(4);
//	a.push_back(5);
//	a.push_back(6);
//	a.push_back(7);
//
//	a.erase(++a.begin());
//	for (auto e : a)
//	{
//		cout << e<<endl;
//	}
//	for (auto it = --a.end(); it != a.end(); --it)
//	{
//		cout << *it;
//	}
//	return 0;
//
//}

//
//class a
//{
//public:
//	a()
//		:_a(new int[10])
//	{}
//	int* _a;
//};
//
//void fun()
//{
//
//}
