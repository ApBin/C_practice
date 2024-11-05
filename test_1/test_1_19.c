#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0;
	
	printf("%d", ~a);// ~按位取反（按二进制）；整数在内存中储存的是补码
	//-1：
	//10000000000000000000000000000001（原码）最大位表示符号                    //正数 原码 反码 补码 不变
	//11111111111111111111111111111110（反码）最大位不变；其他位按位取反
	//11111111111111111111111111111111（补码）最后位加1
	//

	return 0;
}

int main()
{
	int a = 10;
	int b = ++a;//前置++ 先加后使用
	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}

int main()
{
	int a =(int) 3.14;// （int)强制类型转化  不推荐

	printf("%d", a);

	return 0;
}

int main()
{
	int a = 3;
	int b = 8;

	int c = a && b;//并且 a b 都为真为，结果为真 否者为假
	int d = a || b;//或者 有一方为真就真

	printf("%d", c);

	return 0;
}

int main()
{
	//exp1 ? exp2 : exp3;//exp1成立，exp2计算，结果为exp2结果，否者exp3
	int a = 1;
	int b = 8;
	int MAX = 0;
	
	/*if (a > b)
	    MAX = a;

	else
		MAX = b;*/

	MAX = a > b ? a : b;

	printf("%d", MAX);

	return 0;
}