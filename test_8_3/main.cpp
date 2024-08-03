#include <iostream>
#include <cassert>
using namespace std;

 void test(int a = 4)
 {
    cout<<a<<endl;
 }   
/*
int main()
{
    test();// 没有传参时，使⽤参数的默认值
    test(22);// 传参时，使⽤指定的实参

    return 0;
}*/


// 全缺省
void test2(int a = 2, int b = 4, int c = 6)
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
} 

// 半缺省(半缺省参数必须从右往左依次连续缺省，不能间隔跳跃给缺省值)
void test3(int a, int b = 40, int c = 60)
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
}
/*
int main()
{
    //带缺省参数的函数调⽤，C++规定必须从左到右依次给实参，不能跳跃给实参
    test2();
    test2(10);
    test2(10,20);
    test2(10,20,30);
    test3(100);
    test3(100, 200);
    test3(100, 200, 300);

    return 0;
}*/

// Stack.h
#include <iostream>
#include <assert.h>
using namespace std;

typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps, int n = 4);

// Stack.cpp
//#include"Stack.h"
// 缺省参数不能声明和定义同时给
void STInit(ST* ps, int n)
{
    assert(ps && n > 0);
    ps->a = (STDataType*)malloc(n * sizeof(STDataType));
    ps->top = 0;
    ps->capacity = n;
}


// test.cpp
//#include"Stack.h"
int main()
{
    ST s1;
    STInit(&s1);
    // 确定知道要插⼊1000个数据，初始化时⼀把开好，避免扩容
    ST s2;
    STInit(&s2, 1000);

    return 0;
}

