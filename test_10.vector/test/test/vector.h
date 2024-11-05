#pragma once
#include <iostream>
#include <assert.h>
namespace bin
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(initializer_list<T> il)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(il.size());
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * oldSize);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + oldSize;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;*/

			insert(_finish, x);
		}

		bool empty()
		{
			return _start == _finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator i = _finish - 1;
			while (i >= pos)
			{
				*(i + 1) = *i;
				--i;
			}
			*pos = x;
			++_finish;
		}

		void erase(iterator pos);

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
