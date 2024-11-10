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

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//解决int,int的问题
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		/*vector(initializer_list<T> il)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(il.size());

			for (auto& e : il)
			{
				push_back(e);
			}
		}*/

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& tmp)
		{
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
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

		T& operator[](size_t i) const
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

		void resize(size_t n, T val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * oldSize);//浅拷贝，值拷贝
					for (size_t i = 0; i < oldSize; i++)
					{
						tmp[i] = _start[i];
					}

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

		//迭代器失效问题，需要返回pos
		iterator insert(iterator pos, const T& x)
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

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator i = pos + 1;
			while (i < _finish)
			{
				*(i - 1) = *i;
				++i;
			}
			_finish--;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
