#include"string.h"

void test1()
{
	//char a[] = "hello world";
	bin::string s1("hello world");
	//string s2(s1);
	//string s3(s1, 0, 2);
	//string s4(a, 3);
	//string s5(10, '2');

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;

	//string::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;

	////范围for(语法糖
	////自动取容器数据赋值给左边
	////自动++，自动判断结束
	/*for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;*/

	//cout << s5 << endl;
	//for (auto& ch : s5)//修改
	//{
	//	cout << ++ch;
	//}
	//cout << endl;

	////c++20支持
	////void func1(auto x);
}
void test2()
{
	bin::string s2("hello world");
	cout << s2.c_str() << endl;

	s2 += ' ';
	s2 += "asd";
	cout << s2.c_str() << endl;

	s2.insert(0, 'x');
	cout << s2.c_str() << endl;

	s2.insert(5, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	cout << s2.c_str() << endl;
}

void test3()
{
	bin::string s3("hello world");
	cout << s3.c_str() << endl;

	s3.erase(6, 2);
	cout << s3.c_str() << endl;
	s3.erase(3);
	cout << s3.c_str() << endl;
}

void test4()
{
	bin::string s4("hello world");
	cout << s4.c_str() << endl;
	cout << s4.find(' ') << endl;
	cout << s4.find("wo") << endl;

	s4 = s4;

	bin::string s1 = "https://legacy.cplusplus.com/reference/cstring/strstr/?kw=strstr";
	size_t pos1 = s1.find(':');
	size_t pos2 = s1.find('/', pos1 + 3);
	if (pos1 != string::npos && pos2 != string::npos)
	{
		bin::string domain = s1.substr(pos1 + 3, pos2 - (pos1 + 3));
		cout << domain.c_str() << endl;

		bin::string uri = s1.substr(pos2 + 1);
		cout << uri.c_str() << endl;
	}
}

void test5()
{
	bin::string s1("hello world");
	bin::string s2(s1);
	bin::string s3 = s1;
	bin::string s4 = "hello world";
	cout << (s1 == s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 == "hello world") << endl;
	cout << ("hello world" == s1) << endl;
}

void test6()
{
	bin::string s1("hello world");
	cout << s1 << endl;

	bin::string s2;
	cin >> s2;
	cout << s2 << endl;

	getline(cin, s2, '#');
	cout << s2 << endl;
}
void test7()
{
	bin::string s1("hello world");
	bin::string s2("XXXXXXXXXXXXX");
	s1.swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;
}
void test8()
{
	bin::string s1("hello world");
	bin::string s2(s1);
	bin::string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	bin::string s4 = s3;
	cout << s4;
}

int main()
{
	/*string s1("once hello world");
	cout << s1 << endl;*/
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test8();

	return 0;
}