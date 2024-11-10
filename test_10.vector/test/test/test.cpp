#include "vector.h"

void test1()
{
	bin::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	v1.pop_back();
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	v1.pop_back();
	bin::vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		std::cout << *it1 << " ";
		++it1;;
	}
	std::cout << std::endl;
}

void test2()
{
	bin::vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v1.insert(v1.begin() + 2, 30);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	v1.resize(15, 1);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	v1.resize(5);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}