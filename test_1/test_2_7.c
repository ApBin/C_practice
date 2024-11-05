#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("###########################\n");
	printf("########  1.play   ########\n");
	printf("########  0.exit   ########\n");
	printf("###########################\n");
}

void game()
{
	int guess = 0;
	//1.生成随机数
	//0-99 --> 1-100
	int ret = rand()%100+1;//生成随机数的函数，范围 0-RAND_MAX（32767）(16进制)
	printf("%d\n", ret);
	//2.猜数字
	while(1)
	{
		printf("猜猜看数字:>");
		scanf("%d", &guess);
		if (guess < ret)
			printf("猜小了\n");
		else if (guess > ret)
			printf("猜大了\n");
		else
		{
			printf("猜对了，GOOD!!!\n");
			break;
		}
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置起点，时间戳
	do
	{
		menu();
		printf("请选择");  
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("开始游玩\n");
		        game();
			   break;
		case 0:
		        printf("退出\n");
			   break;
		default:
				printf("miss\n");
		       break;

		}

	} while (input);
	return 0;
}