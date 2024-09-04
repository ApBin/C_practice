#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month)
	{
		if (month == 2 && year % 4 == 0 && year % 100 == 0 || year % 400 == 0)
		{
			return 29;
		}

		static int	Day[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		return Day[month];
	}

	bool CheckDate()
	{
		if (_year < 1900 || _month>12 || _day<1 || _day>GetMonthDay(_year, _month))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		if (!CheckDate())
		{
			cout << " Miss-> ";
			cout << *this << endl;
		}
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
			if (_month == 13)
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

	// >运算符重载

	bool operator>(const Date& d)
	{
		return !(*this < d);
	}

	// ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// >=运算符重载

	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <运算符重载

	bool operator < (const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year
			&& _month < d._month)
		{
			return true;
		}
		else if (_year == d._year
			&& _month == d._month
			&& _day < d._day)
		{
			return true;
		}
		return false;
	}

	// <=运算符重载

	bool operator <= (const Date& d)
	{
		return *this < d || *this == d;
	}

	// !=运算符重载

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// -运算符重载

	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;

		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}

		return day * flag;
	}

private:

	int _year;
	int _month;
	int _day;
};

// <<重载
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "Y-" << d._month << "M-" << d._day << "D" << endl;
	return out;
}

// >>重载
istream& operator>>(istream& in, Date& d)
{
	do
	{
		cout << "连续输入年月日:>";
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
		{
			cout << " Miss " << endl;
			cout << "重新输入" << endl;
		}
	} while (!d.CheckDate());

	return in;
}

int main()
{
	Date d1(2024, 9, 3);
	d1.Print();
	Date d2(2024, 10, 1);
	d2.Print();
	cout << "d2-d1" << " " << d2 - d1 << endl;
	d1 += 100;
	d1.Print();
	cout << d1 << d2;
	Date d3;
	cin >> d3;
	d3.Print();

	return 0;
}