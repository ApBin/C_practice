#include<iostream>
using namespace std;
/*
int main()
{
	int a = 0;
	// 引⽤：b和c是a的别名
	int& b = a;
	int& c = a;
	// 也可以给别名b取别名，d相当于还是a的别名
	int& d = b;
	// 这⾥取地址我们看到是⼀样的
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;

	return 0;
}

int main()
{
	int a = 10;
	// 编译报错：“ra”: 必须初始化引⽤
	//int& ra;
	int& b = a;
	int c = 20;
	// 这⾥并⾮让b引⽤c，因为C++引⽤不能改变指向，
	// 这⾥是⼀个赋值
	b = c;
	cout << &a <<" "<< a << endl;
	cout << &b <<" "<< b << endl;
	cout << &c <<" "<< c << endl;

	return 0;
} 


void Swap(int& rx, int& ry)
{
	int tmp = rx;
	rx = ry;
	ry = tmp;
} 

int main()
{
	int x = 0, y = 1;
	cout << x <<" " << y << endl;
	Swap(x, y);
	cout << x << " " << y << endl;
	return 0;
}
*/
#include<iostream>
#include<assert.h>
using namespace std;

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST& rs, int n = 4)
{
	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
	rs.top = 0;
	rs.capacity = n;
}

// 栈顶
void STPush(ST& rs, STDataType x)
{
	//assert(rs);
	// 满了， 扩容
	if (rs.top == rs.capacity)
	{
		printf("扩容\n");
		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			} 
		rs.a = tmp;
		rs.capacity = newcapacity;
	} 
	rs.a[rs.top] = x;
	rs.top++;
} 

// int STTop(ST& rs)
int& STTop(ST& rs)
{
	//assert(rs.top > 0);
	return rs.a[rs.top];
}

int main()
{
	// 调⽤全局的
	ST st1;
	STInit(st1);
	STPush(st1, 1);
	STPush(st1, 2);
	cout << STTop(st1) << endl;
	STTop(st1) += 10;
	cout << STTop(st1) << endl;
	return 0;
}