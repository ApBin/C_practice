#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 0, double b = 1)
		:_a(a)
		, _b(b)
	{
		cout << "A()" << _a << endl;
	}

	~A()
	{
		cout << "~A()" << _a << endl;
	}

private:
	int _a = 2;
	double _b;
};

template<class T>
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		_array = new T[capacity];
		_capacity = capacity;
		_size = 0;

		cout << "Stack" << " " << _capacity << endl;
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
T Swap(T& Left, T& right)
{
	return (left + right);
}

template<class T1, class T2>
T1 Swap(T1& Left, T2& right)
{
	return (left + right);
}

int main()
{
	/*int a1 = 10, a2 = 5;
	double d1 = 2.1, d2 = 5.1;
	cout << Swap(a1, d2) << endl;
	cout << Swap<int>(a1, a2) << endl;*/

	/*int* p1 = new int;
	int* p1 = new int[2];
	int* p1 = new int[6] {1, 2, 3};

	A aa1(1);
	A aa2(2);
	A* p1 = new A;
	A* p2 = new A(5);
	A* p3 = new A[3]{ aa1,aa2 };
	delete p1;
	delete p2;
	delete[] p3;*/

	//A* p6 = (A*)operator new(sizeof(A));
	//new(p6)A(10);//定位new；构造不支持显示调用
	//p6->~A();//显示稀构调用

	/*void* p4 = operator new(sizeof(A));
	operator delete(p4);
	p4 = nullptr;*/

	//stack<int>才是类型
	Stack<int>st1;
	Stack<double>st2;

	return 0;
}