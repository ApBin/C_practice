#include "string.h"

namespace bin
{
	const size_t string::npos = -1;

	/*	string::string()
			:_str(new char[1] {'\0'})
			, _size(0)
			, _capacity(0)
		{}*/

	string::string(const char* str)
		: _size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_size + 1];

		strcpy(_str, str);
	}
	//s2(s1)传统写法
	/*string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	string& string:: operator=(const string& s)
	{
		if (this != &s)
		{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
		}
		return *this;
	}*/

	//现代写法
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);
	}

	string& string:: operator=(string s)
	{
		if (this != &s)
		{
			swap(s);
		}
		return *this;
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		_size++;
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newCapacity = 2 * _capacity;
			//扩两倍不够，需多少扩多少
			if (newCapacity < _size + len)
				newCapacity = _size + len;

			reserve(newCapacity);
		}

		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator += (char ch)
	{
		push_back(ch);

		return *this;
	}

	string& string::operator += (const char* str)
	{
		append(str);

		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		/*size_t end = _size;
		while (end >= (int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		_size++;*/

		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		_size++;
	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newCapacity = 2 * _capacity;
			//扩两倍不够，需多少扩多少
			if (newCapacity < _size + len)
				newCapacity = _size + len;

			reserve(newCapacity);
		}

		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + len] = _str[end];
			--end;
		}

		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				++end;
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (ch == _str[i])
				return i;
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos)
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return  ptr - _str;
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		//大鱼后面剩余长度，直接取到结尾；
		if (len > (_size - pos))
		{
			len = _size - pos;
		}

		bin::string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}
		return sub;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	/// ////////////////////////////////////////////////////////////

	void swap(string& s1, string& s2)
	{
		s1.swap(s2);
	}

	bool operator == (const string& lhs, const string& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) == 0;
	}
	bool operator != (const string& lhs, const string& rhs)
	{
		return !(lhs == rhs);
	}
	bool operator > (const string& lhs, const string& rhs)
	{
		return !(lhs <= rhs);
	}
	bool operator < (const string& lhs, const string& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) < 0;
	}
	bool operator >= (const string& lhs, const string& rhs)
	{
		return !(lhs < rhs);
	}
	bool operator <= (const string& lhs, const string& rhs)
	{
		return lhs < rhs || lhs == rhs;
	}

	ostream& operator<<(ostream& os, const string& str)
	{
		os << '"';
		for (size_t i = 0; i < str.size(); i++)
		{
			os << str[i];
		}
		os << "\" " << endl;
		return os;
	}

	istream& operator>>(istream& is, string& str)
	{
		str.clear();

		int i = 0;
		char buff[256];

		char ch;
		//is >> ch;
		ch = is.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 255)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			//str += ch;
			//is >> ch;
			ch = is.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}
		return is;
	}

	istream& getline(istream& is, string& str, char delim)
	{
		str.clear();

		int i = 0;
		char buff[256];

		char ch;
		//is >> ch;
		ch = is.get();
		while (ch != delim)
		{
			buff[i++] = ch;
			if (i == 255)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			//str += ch;
			//is >> ch;
			ch = is.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}
		return is;
	}
}