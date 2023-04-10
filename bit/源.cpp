#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s

#include<stdio.h>

void print_32()
{
	int i;
	for (i = 1; i < 33; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
}
//
//int main()
//{
//	int num;
//	printf("请输入操作数:\n");
//	scanf("%d", &num);
//	int i = 0,i_2=1;
//	int odd[16] = { 0 }, even[16] = { 0 };//创建数组存放奇偶位二进制数
//	for (i = 0; i < 32; i++)
//	{
//		if (i_2 == (num & i_2))
//		{
//			if (i % 2 == 0)
//			{
//				odd[i / 2] = 1;
//			}
//			else
//			{
//				even[i / 2] = 1;
//			}
//		}
//		else
//		{
//			if (i % 2 == 0)
//			{
//				odd[i / 2] = 0;
//			}
//			else
//			{
//				even[i / 2] = 0;
//			}
//		}
//		i_2 <<=1;
//		//printf("%d\n", i_2);
//	}
//	printf("您输入的数字的二进制奇数位是：\n");
//	print_32();
//	for (i = 0; i < 16;i++)
//	{
//		printf("%3d   ", odd[i]);
//	}
//	printf("\n您输入的数字的二进制偶数位是：\n");
//	print_32();
//	for (i = 0; i < 16;i++)
//	{
//		printf("   %3d", even[i]);
//	}
//	printf("\n\n\n所有位:\n");
//	print_32();
//	for (i = 0; i < 32; i++)
//	{
//		if (i % 2 == 0)
//		{
//			printf("%3d", odd[i / 2]);
//		}
//		else
//		{
//			printf("%3d", even[i / 2]);
//		}
//	}
//	return 0;
//}


int main()
{
	int num;
	printf("请输入操作数:\n");
	scanf("%d", &num);
	int i = 0, i_2 = 1;
	int odd[16] = { 0 }, even[16] = { 0 };//创建数组存放奇偶位二进制数
	for (i = 0; i < 32; i++)
	{
		
		if (num%2)
		{
			if (i % 2 == 0)
			{
				odd[i / 2] = 1;
			}
			else
			{
				even[i / 2] = 1;
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				odd[i / 2] = 0;
			}
			else
			{
				even[i / 2] = 0;
			}
		}
		num /= 2;
		//printf("%d\n", i_2);
	}
	printf("您输入的数字的二进制奇数位是：\n");
	print_32();
	for (i = 0; i < 16; i++)
	{
		printf("%3d   ", odd[i]);
	}
	printf("\n您输入的数字的二进制偶数位是：\n");
	print_32();
	for (i = 0; i < 16; i++)
	{
		printf("   %3d", even[i]);
	}
	printf("\n\n\n所有位:\n");
	print_32();
	for (i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			printf("%3d", odd[i / 2]);
		}
		else
		{
			printf("%3d", even[i / 2]);
		}
	}
	return 0;
}

