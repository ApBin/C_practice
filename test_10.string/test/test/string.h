#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace bin
{
	class string
	{
	public:
		//typedef char* iterator;
		using iterator = char*;
		using const_iterator = const char*;

		//string();
		string(const char* str = "");
		string(const string& s);
		string& operator=(string s);
		~string();

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator += (char ch);
		string& operator += (const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos, size_t len = npos);
		void swap(string& s);

		char& operator[](size_t i)
		{
			assert(i < _size);

			return _str[i];
		}

		const char& operator[](size_t i)const
		{
			assert(i < _size);

			return _str[i];
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		size_t size()const
		{
			return _size;
		}

		const char* c_str()const
		{
			return _str;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str; //°´Ë³Ðò³õÊ¼»¯
		size_t _size;
		size_t _capacity;

	public:
		static const size_t npos;
	};

	void swap(string& s, string& s2);
	bool operator == (const string& lhs, const string& rhs);
	bool operator != (const string& lhs, const string& rhs);
	bool operator > (const string& lhs, const string& rhs);
	bool operator < (const string& lhs, const string& rhs);
	bool operator >= (const string& lhs, const string& rhs);
	bool operator <= (const string& lhs, const string& rhs);
	ostream& operator<<(ostream& os, const string& str);
	istream& operator>>(istream& is, string& str);
	istream& getline(istream& is, string& str, char delim = '\n');
}