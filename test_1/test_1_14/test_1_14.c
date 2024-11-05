#include <stdio.h>

int main()
{
	printf("hehe\n");

	return 0;
}

//作用域和生命周期

//作用域
//局部变量的作用域：就是变量所在的局部范围
//全局变量的作用域：整个工程

int g_val = 2024;//全局变量

int main()
{
	printf("1:%d\n", g_val);

	printf("haha\n");
	{
		printf("2:%d\n", g_val);

		int a = 10;
		printf("a=%d\n", a);
	}
	printf("3:%d\n", g_val);

	return 0;
}

//声明一下变量
extern int w;

int main()
{
	printf("%d\n", w);

	return 0;
}

//生命周期
//变量的生命周期：变量的创建和销毁之间的时间段

//局部变量的生命周期：进入局部范围生命开始，出局部范围生命结束
//全局变量的生命周期：程序的生命周期

int main()
{
	{
		int c = 10;
		printf("%d\n", c);
	}

	return 0;
}

