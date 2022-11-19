#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
void menu()
{
	printf("*************************************************\n");
	printf("********************            *****************\n");
	printf("********************   0.exit   *****************\n");
	printf("********************   1.play   *****************\n");
	printf("********************            *****************\n");
	printf("*************************************************\n");
}
void game()
{
	int k;
	srand((unsigned int)time(NULL));
	int num = rand();//生成随机数
	num = num % 100 + 1;
	printf("what's your gess num?\n");
	//printf("%d\n",num );
	for (scanf("%d",&k);k!=num; scanf("%d", &k))
	{
		
		//猜数字部分
		if (k < num)
			printf("It's too small\n");
		else if (k > num)
			printf("It's too big\n");
	}
	printf("Congretulations!!!!!!!!!\nYou Win!!!!!!!!!!\n");
	
}
int  main()
{
	{
		int elect=1;
		while (elect)
		{
			menu();
			scanf("%d", &elect);
			

				game();
		}


	}

	return 0;
}