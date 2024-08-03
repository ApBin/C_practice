#include <iostream>
using namespace std;

// 1、参数类型不同
int test1(int a, int b)
{
    cout<< "参数类型不同1" <<endl;
    return a + b;
}

double test1(double a, double b)
{
    cout<< "参数类型不同2" <<endl;
    return a + b;
}
/*
int main()
{
    test1(1, 2);
    test1(1.1, 2.2);

    return 0;
}*/

// 2、参数个数不同
void test2()
{
    cout<< "参数个数不同1" <<endl;
}

void test2(int a)
{
    cout<< "参数个数不同2" <<endl;
}
/*
int main()
{
    test2();
    test2(10);

    return 0;
}*/

// 3、参数类型顺序不同
void test3(int a, char b)
{
    cout<< "参数类型顺序不同1" <<endl;
}

void test3(char b, int a)
{
    cout << "参数类型顺序不同2" << endl;
}

/*
int  main()
{
    test3(1, 'a');
    test3('a', 1);

    return 0;
}*/

//返回值不同不能作为重载条件
//因为调用时也无法区分
void test4(int b, int a)
{
    cout<< b+a;
}
/*
int test4(int b, int a)
{
    return 1;
}*/


// 下⾯两个函数构成重载
// test5()调⽤时，会报错，存在歧义，编译器不知道调⽤谁
void f1()
{
    cout<< "f()" <<endl;
} 

void f1(int a = 10)
{
    cout<< "f(int a)" <<endl;
}

int main()
{
    test4(1, 2);

    return 0;
}