#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<windows.h>
int main()
{
	char arr1[] = "welcome to bit!!!";
	char arr2[] = "#################";

	int left = 0;
	int reght = strlen(arr2) - 1; //slzeof(arr2) / slzeof(arr2[0]) - 2;
	for (; left <= reght;)
	{
		arr2[left] = arr1[left];
		arr2[reght] = arr1[reght];

		printf("%s\n", arr2);
		left++;
		reght--;
		Sleep(1000);
		system("cls");//库函数执行系统命令"清屏"
	}
	printf("%s\n", arr2);

	return 0;
}

#include<string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", password);
		if (strcmp(password, "abcd") == 0)//比较两字符串是否相等,返回值为0表示字符串相等
		{
			printf("密码正确\n");
			break;
		}
		else
			printf("miss\n");

	}
	if (i >= 3)
		printf("错误过多，退出程序\n");
	


	return 0;
}