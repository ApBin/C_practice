#include <iostream>
using namespace std;

class Date
{

public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month)
	{
		if (month == 2 && year % 4 == 0 && year % 100 == 0 || year % 400 == 0)
		{
			return 29;
		}

		static int	Day[13] = { -1,31,29,31,30,31,30,31,31,30,31,30,31 };
		return Day[month];
	}



	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 || month>12 || day<1 || day>GetMonthDay(year, month))
			cout << "错误日期" << endl;

		_year = year;
		_month = month;
		_day = day;
	}



	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 析构函数
	//~Date();

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 日期+=天数

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month > 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}



	// 日期+天数

	Date operator+(int day)
	{
		Date ret = *this;
		ret += day;

		return ret;
	}



	// 日期-天数

	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;

		return tmp;
	}



	// 日期-=天数

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_month = 12;
				--_year;
			}

			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}


	// 前置++

	Date& operator++()
	{
		*this += 1;
		return *this;
	}



	// 后置++

	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}



	// 后置--

	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}



	// 前置--

	Date& operator--()
	{
		*this += 1;
		return *this;
	}



	//// >运算符重载

	//bool operator>(const Date& d);



	//// ==运算符重载

	//bool operator==(const Date& d);



	//// >=运算符重载

	//bool operator >= (const Date& d);



	//// <运算符重载

	//bool operator < (const Date& d);



	//// <=运算符重载

	//bool operator <= (const Date& d);



	//// !=运算符重载

	//bool operator != (const Date& d);



	//// 日期-日期 返回天数

	//int operator-(const Date& d);

private:

	int _year;

	int _month;

	int _day;

};

int main()
{
	Date d1(2024, 9, 3);
	d1.Print();
	return 0;
}