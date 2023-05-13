#pragma once
//contact头文件
// 
// 
//模仿通讯录的功能
// 存储信息：名字，性别，年龄，电话，地址
// 功能：增删查改，查找，显示，排序
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define DATA_MAX 100//Contact与PeoInfo结构体数组成员大小
#define NAME_MAX 20
#define SEX_MAX 5
#define PHONE_MAX 12
#define ADDRESS_MAX 40
#define MALLOCINIT_SZ 3
#define REALLOCADD_SZ 2
//表示一个人的信息
struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
	int age;
};
struct Contact
{
	struct PeoInfo *data;
	int sz;
	int MemSz;
}contact;
void Init_contact(struct Contact* pc);
void AddConact(struct Contact* pc);
void ShowContact(struct Contact* pc);
void DelContact(struct Contact* pc);
void SearchContact(struct Contact* pc);
void ModifyContact(struct Contact* pc);
void SortConact(struct Contact* pc);

//
// 
// 本项目仅为熟悉结构体及一些函数的使用而创建，为了将更多的时间投入学习很多功能并未添加，是半成品中的半成品
// 这里提供一些日后的改进方案，如有空，或许未来会实现
// 
//
//程序的改进方案：
//为用户提供按多种方式的排序，记录用户的排序方式
//做到其他功能发挥之后，数据的排序方式依然不改变（修改功能后自动重排一次，或者将修改数据插入到对应位置
//在以上的前提上，我们在查找的时候可以使用二分查找
//		可以创建一个全局变量（待考虑）），然后在比较数组中进行操作
//		整合的时候创建变量（main函数中）再选择排序和查找时的比较数组