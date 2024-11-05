#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int add(int X, int Y)
{
	int asd = X + Y;

	return asd;
}

int main()
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);
	int sum = num1 + num2;
	int sum = add(num1, num2);

	printf("%d", sum);

	return 0;
}

int main()
{
	//数组-一组相同类型的元素集合
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//char ch[5] = { 'a','b','c' };//不完全初始化，剩余默认为0
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i = i++;
	}

	return 0;
}

int main()
{
	int a = 9 / 2;
	float b = 9 / 2;
	float c = 9 / 2.0;
	int d = 9 % 2;//%-取模（取余）

	printf("%d\n", a);//4
	printf("%f\n", b);//4.000000
	printf("%f\n", c);//4.500000
	printf("%d\n", d);//1

	return 0;
}

int main()
{
	int a = 2;
	int b = a << 1;//左移动操作符-移动的是二进制位
	//00000000000000000000000000000010    int-4字节；1字节8bit位
	//向左移动一位
	//00000000000000000000000000000100    最后一位补0
	printf("%d", b);//4

	return 0;
}

//位操作符：
// &按位与
// |按位或
// ^按位异或

//赋值操作符
int main()
{
	a = a + 5;
	a += 5;

	a = a - 5;
	a -= 5;

	a = a % 5;
	a %= 5;

	return 0;
}

//单目操作符：只有一个操作数
// ！逻辑反操作

int main()
{
	//0表示假，非0表示真
	int a = 10;
	int b = 0;

	printf("%d\n", !a);//真假互换
	printf("%d\n", !b);//假变真默认为1

	if (a)
	{
		//a为真就做事
	}
	if (!a)
	{
		//a为假就不做事
	}
}

int main()
{
	int a = 10;
	//sizeof是一个操作符
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(a));//操作符括号可省略
	
	return 0;
}

int main()
{
	
	int arr[10] = { 0 };
	printf("%d\n", sizeof arr);//10 * 4 = 40
	printf("%d\n", sizeof arr[0]);
	printf("%d\n",sizeof arr / sizeof arr[0]);//求组数

	return 0;
}