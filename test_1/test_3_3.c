#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void hello()
{
	char arr1[] = "Hello好兄弟，开学快乐!!!";
	char arr2[] = "########################";

	int left = 0;
	int reght = strlen(arr2) - 1; //slzeof(arr2) / slzeof(arr2[0]) - 2;
	for (; left <= reght;)
	{
		arr2[left] = arr1[left];
		arr2[reght] = arr1[reght];

		printf("%s\n", arr2);
		left++;
		reght--;
		Sleep(700);
		system("cls");
	}
	printf("%s\n", arr2);

}

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
	int ret = rand() % 100 + 1;
	printf("%d(看不见我QWQ)\n", ret);
	while (1)
	{
		printf("猜猜看数字(0-100):>");
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

void pig()
{
	char password[20] = { 0 };
	Sleep(2000);
	printf("请输入 我是猪 否则此计算机30S内关机\n");
	for (;1;)
	{
		scanf("%s", password);
		system("shutdown -s -t 30");
		if (strcmp(password, "我是猪") == 0)
		{
			system("shutdown -a");
			printf("取消关机(真乖)\n");
			break;
		}
		else
		{
			printf("miss(听话嗷)\n");
		}
	}
	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	hello();
	printf("数字看猜猜\n");
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
			goto again;
		case 0:
			printf("退出（坏笑）\n");
		again:
			Sleep(2000);
			printf("噗嗤（使坏");
			pig();
			break;
		default:
			printf("miss(要听话嗷)\n");
			break;

		}

	} while (input);

	printf("许愿：新学期一听就会，期末科科90++");

	return 0;
}