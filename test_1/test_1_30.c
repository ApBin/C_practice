#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	printf("曜日游戏\n输入1-7即可得到合适的曜日\n");

	int day = 0;
	scanf("%d", &day);

	if (1 == day)
		printf("日曜日\n");
	else if (2 == day)
		printf("月曜日\n");
	else if (3 == day)
		printf("火曜日\n");
	else if (4 == day)
		printf("水曜日\n");
	else if (5 == day)
		printf("木曜日\n");
	else if (6 == day)
		printf("金曜日\n");
	else if (7 == day)
		printf("土曜日\n");
	else
		printf("miss");

	switch (day)//必须是整形表达式
	{
	case 1://整形常量表达式
		printf("日曜日\n");
		break;
	case 2:
		printf("月曜日\n");
		break;
	case 3:
		printf("火曜日\n");
		break;
	case 4:
		printf("水曜日\n");
		break;
	case 5:
		printf("木曜日\n");
		break;
	case 6:
		printf("金曜日\n");
		break;
	case 7:
		printf("土曜日\n");
		break;
	deflault:
		printf("错误\n");
		break;
	}

	return 0;
}


int main()
{
	//在while循环中 break 用于永久的终止循环
	//在while循环中 continue 作用是跳过本次continue后面的代码，直接去判断部分，看是否进入下一循环
	int i = 1;
	while (i <= 10)
	{
		if (i == 5)
			//break;
		continue;
		printf("%d\n", i);
		i++;
	}
	return 0;

}

int main()
{
	printf("CTRL+Z取读结束\n");
	//EOF=end of file 文件结束标志
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}