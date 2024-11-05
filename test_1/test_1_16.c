#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//转义字符
int main()
{
	printf("c:\\test\.c");//转义字符\

		return 0;
}

int main()
{
	//\ddd :ddd表示1-3个八进制的数字
	//\ddd :dd表示2个十六进制数字
	//printf("%c\n", '\130');//X——ASCII码值是88——8进制是130
	//printf("%c\n", '\101');//A——65——101
	//printf("%c\n", '\x30');//0——48——x30

	printf("%d\n", strlen("c:\test\328\test.c"));//14

	return 0;
}


// C++注释风格 - 可注释一行也可以注释多行

/* 
C注释风格 - 不支持嵌套注释
*/

int main()
{
	int input = 0;

	printf("加入卷狗大队\n");
	printf("每天要敲代码么?（1/0)\n");
	scanf("%d", &input);

	if (input == 1)
		printf("好offer\n");
	else
		printf("卖地瓜\n");

	return 0;
}

//while循环
int main()
{
	int line = 0;
	while(line<=30000)
	{
		printf("敲代码:%d\n",line);
		line++;
	}
	if (line == 30001)
	{
		printf("好offer\n");
	}

	return 0;
}