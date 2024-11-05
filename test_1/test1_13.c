#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("比特\n");

	return 0;
}


//char         //字符数据类型
//short        //短整型
//int          //整形
//long         //长整形
//long long    //更长整形
//float        //单精度浮点数
//double       //双精度浮点数



int main()
{
	printf("hehe\n");
	printf("bite\n");
	printf("%d\n", 100);
	printf("%d\n", sizeof(char));//sizeof-计算类型或者变量所占空间大小
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

	return 0;
}


//%d-整型
//%f-单精度浮点数
//%lf-双精度浮点数

int main()
{
	int age = 20;
	double weight = 57.3;

	age = age + 1;
	weight = weight - 20;
	printf("%d\n", age);
	printf("%lf\n",weight);

	return 0;

}

//全局变量-{}外部定义的
int a = 100;

int main()
{
	//局部变量-{}内部定义的
	//全局变量和局部变量名字冲突时，局部优先
	//不建议把全局变量和局部变量的名字写成一样的
	int a = 10;

	printf("%d\n", a);

	return 0;
}


//写一个代码求2个整数的和
//scanf函数是输入函数

int main()
{
	int a = 0;
	int b = 0;
	int sum = 0;

	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);

	return 0;

}