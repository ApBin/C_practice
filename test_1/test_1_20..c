#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef unsigned int u_int;//简单化
int main()
{
	unsigned int num = 100;
	u_int num2 = 100;

	return 0;
}

//static -静态的
//1.static修饰局部变量，改变了局部变量的生命周期（本质是改变存储类型为静态区
//2.static修饰全局变量，使得被修饰的全局变量只能在自己所在的源文件(.c)内使用（外部链接属性变内部链接属性
//3.stasic修饰函数，使得被修饰的函数只能在自己所在的源文件(.c)内使用（外部链接属性变内部链接属性

void test()
{
	static int a = 1;//stastic修饰局部变量，

	a++;
	printf("%d", a);
}
int main()
{
	int i = 0;
	while (i < 10)
	{
	test();
	i++;
}
	return 0;
}

//define 是一个预处理指令
//define 定义符号

#define MAX 1000

int main()
{
	printf("%d\n", MAX);
	return 0;
}

//define 定义宏
#define ADD(X,Y) ((X)+(Y))

int main()
{
	printf("%d\n", 4 * ADD(2, 3));

	return 0;

}

int main()
{
	int a = 10;//向内存申请4字节，储存10
	int* pa = &a;//pa指针变量
	 *pa = 20;//解引用操作符，通过pa中存放的地址，找到pa所指向的对象,*pa就是pa指向的对象
		printf("%d", a);

	return 0;
}

int main()
{//不管什么类型的指针，都是在创建指针变量
	//指针变量是用来存放地址的
	//指针变量的大小取决于一个地址存放的时候需要多大的空间
	//32位机器上的地址:32bit位 - 4byte,所以指针变量的大小是4个字节
	//64位机器上的地址:64bit位 - 8byte,所以指针变量的大小是8个字节
	printf("%d\n", sizeof(char*));//4
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));

	return 0;
}