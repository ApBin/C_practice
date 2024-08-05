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
	return rs.a[rs.top - 1];
}
/*
int main()
{
	// 调⽤全局的
	ST st1;
	STInit(st1);
	STPush(st1, 1);
	STPush(st1, 2);
	cout << STTop(st1) << endl;
	// 修改栈顶的数据呢
	STTop(st1) += 1;
	cout << STTop(st1) << endl;
	return 0;
}

typedef struct SeqList
{
	int a[10];
	int size;
}SLT;
// ⼀些主要⽤C代码实现版本数据结构教材中，使⽤C++引⽤替代指针传参，⽬的是简化程序
//避开复杂的指针，但是很多同学没学过引⽤，导致⼀头雾⽔。
void SeqPushBack(SLT& sl, int x)
{
	//...
}
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}LTNode, *PNode;

// 指针变量也可以取别名，这⾥LTNode*& phead就是给指针变量取别名
// 这样就不需要⽤⼆级指针了，相对⽽⾔简化了程序
//void ListPushBack(LTNode** phead, int x)
//void ListPushBack(LTNode*& phead, int x)
void ListPushBack(PNode& phead, int x)
{
	PNode newnode = (PNode)malloc(sizeof(LTNode));
	newnode->val = x;
	newnode->next = NULL;
	if (phead == NULL)
	{
	phead = newnode;
	}
	else
	{
	//...
	}
}

int main()
{
	const int a = 10;
	// 编译报错：error C2440: “初始化”: ⽆法从“const int”转换为“int &”
	// 这⾥的引⽤是对a访问权限的放⼤
	//int& ra = a;
	// 这样才可以
	const int& ra = a;
	// 编译报错：error C3892: “ra”: 不能给常量赋值
	//ra++;
	// 这⾥的引⽤是对b访问权限的缩⼩
	int b = 20;
	const int& rb = b;
	// 编译报错：error C3892: “rb”: 不能给常量赋值
	//rb++;
	return 0;
}
*/
int main()
{
	int a = 10;
	const int& ra = 30;
	// 编译报错: “初始化”: ⽆法从“int”转换为“int &”
	// int& rb = a * 3;
	const int& rb = a*3;
	double d = 12.34;
	// 编译报错：“初始化”: ⽆法从“double”转换为“int &”
	// int& rd = d;
	const int& rd = d;
	return 0;
}