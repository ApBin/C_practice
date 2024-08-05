#include<iostream>
using namespace std;
/*
inline int Add(int x, int y)
{
    int ret = x + y;
    ret += 1;
    ret += 1;
    ret += 1;
    return ret;
} 

int main()
{
    // 可以通过汇编观察程序是否展开
    // 有call Add语句就是没有展开，没有就是展开了
    int ret = Add(1, 2);
    cout << Add(1, 2) * 5 << endl;
    return 0;
}
*/

void f(int x)
{
    cout << "f(int x)" << endl;
} 
void f(int* ptr)
{
    cout << "f(int* ptr)" << endl;
}

int main()
{
    f(0);
    // 本想通过f(NULL)调⽤指针版本的f(int*)函数，
    // 但是由于NULL被定义成0，调⽤了f(intx)，因此与程序的初衷相悖。
    // f(NULL);
    f((int*)NULL);
    // 编译报错：error C2665: “f”: 2 个重载中没有⼀个可以转换所有参数类型
    // f((void*)NULL);
    f(nullptr);

    return 0;
}