#include <stdio.h>

int main()
{
	printf("halo\n");

	return 0;
}

//常量
//1字面常量

int main()
{
	3.14;
	10;
	'a';
	"asdf";
 
	return 0;
}

//2.const修饰的常数
//const int num = 10;//num就是常变量 - 具有常属性（不能被改变的属性）

int main()
{
	const int num = 10;
	//num = 20；
	printf("%d\n", num);//10

	int arr[10] = {0};//10个元素

	const int n = 0;//n的本质任然是变量
	int arr2[n] = { 0 };//n是变量，这里是不行的

	return 0;
}

//3. #define 定义的标识符常量

#define MAX 8848

int main()
{
	int n = MAX;
	//MAX = 44;// #define 定义的标识符常量 不可改
	printf("%d\n", n);

	return 0;
}

//4.枚举常量
//可以一一列举的常量

enum Sex
{
	//这种枚举变量类型的变量的未来可能取值
	//枚举常量
	MALE = 3,//赋初值
	FEMALE,
	SECRET
};

int main()
{
	enum Sex s = MALE;

	printf("%d\n",MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);

	return 0;
}


//字符串就是一串字符 - 用双引号括起来的一串字符

int main()
{
	"asdf"
	"hole heli"
	
	return 0;

}

#include <string.h>

//字符数组 - 数组是一组同类型的元素
//字符串在结尾的位子隐藏了一个\0的字符
//\0是字符串的结束标志
int main()
{
	char arr[] = "hello";//监视结果为六元素第六元素为\0
	char arr1[] = "abc";//4
	char arr2[] = { 'a','b','c' ,'\0'};//4

	//求字符串的长度
	int len = strlen("abc");//sting length
	printf("%d\n", len);//3

	printf("%d\n", strlen(arr1));//3
	printf("%d\n", strlen(arr2));//3,若没有结束标志\0，则为随机值

	//打印字符串
	printf("%s\n", arr1);
	printf("%s\n", arr2);//若没有结束标志\0，会出现随机字符
	
	return 0;
}