#define _CRT_SECURE_NO_WARNINGS 1


#include"vector.h"
#include<vector>
#include<iostream>
using namespace std;

template<class T>
void print(const T&a)
{
	for (auto e: a)
	{
		cout << e<<' ';
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

#include<list>
int main()
{
	//wda::vector<int> v1;
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(4);
	//v1.push_back(5);
	//v1.push_back(6);
	//wda::vector<int>v2(v1.begin(),v1.end());
	//print(v2);
	//wda::vector<long>v1(2,10);

	//wda::vector<std::vector<int>> v1;
	//std::vector<int>v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v1.push_back(v);
	//v1.push_back(v);
	//v1.push_back(v);
	//v1.push_back(v);
	//v1.push_back(v);
	std::list<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	
	wda::vector<int>v2(v1.begin(),v1.end());
	/*for (auto e : v2)
	{
		for (auto e2 : e)
		{
			cout << e2;
		}
		cout << endl;
	}*/
	print(v2);
	return 0;
}

//
//int main()
//{
//	wda::vector<int> a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	a.push_back(4);
//	a.push_back(5);
//	a.push_back(6);
//	//wda::vector<int> a1(a);
//	auto a1=a;
//	//wda::vector<int> a1(a);
//	print(a1);
//	return 0;
//}

//int main()
//{
//	//std::vector<int>a;
//	wda::vector<int>a;
//	a.resize(100);
//	for (int i = 0; i < 100; i++)
//	{
//		//a.push_back(i);
//		a[i] = i;
//	}
//	print(a);
//	for (int i = 0; i < 100; i++)
//	{
//		a.pop_back();
//	}
//	print(a);
//	cout << sizeof(std::vector<int>::iterator);
//	return 0;
//}



//int main()
//{
//	wda::vector<int> a;
//	//std::vector<int> a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	a.push_back(1);
//	a.push_back(1);
//	for (auto& e : a)
//	{
//		++e;
//	}/*
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);
//	a.insert(a.end(), 88);*/
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	a.insert(a.begin(), 88);
//	print(a);
//
//
//
//	cout << '\n';
//	{
//		std::vector<int> a;
//		a.push_back(1);
//		a.push_back(2);
//		a.push_back(3);
//		a.push_back(1);
//		a.push_back(1);
//		for (auto& e : a)
//		{
//			++e;
//		}
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88); 
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		a.insert(a.begin(), 88);
//		print(a);
//
//	}
//	return 0;
//}