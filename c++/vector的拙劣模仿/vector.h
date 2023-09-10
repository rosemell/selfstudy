#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
namespace wda
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const iterator begin()const
		{
			return _start;
		}
		const iterator end()const
		{
			return _finish;
		}
		vector(size_t n,const T&val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())//当T为int时会被下面抢掉，所以再加个int的
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}	
		vector(long n, const T& val = T())//这个好像用不了，有bug
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first++);
			}//更适合所有迭代器宝宝的写法



			//下面代码遇到list的迭代器重载，就遭老罪咯

			//********************************************************
			//********************************************************
			//********************************************************
			//********************************************************
			//********************************************************
			//assert(first < last);
			//size_t sz =last - first;
			//_start = new T[sz];
			//_finish = _start + sz;
			//_end_of_storage = _finish;
			//auto it = _start;
			//while (first < last)
			//{
			//	*it++ = *first++;
			//}
			//********************************************************
			//********************************************************
			//********************************************************

			//上面代码遇到list的迭代器重载，就遭老罪咯
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		~vector()
		{
			delete[]_start;
			_start = _finish = _end_of_storage = nullptr;
		}
		//拷贝构造
	/*	vector(const vector& x)
		{
			if (x.capacity() == 0)
			{
				_start = _finish = _end_of_storage = nullptr;
			}
			else
			{
				_start = new T[x.capacity()];
				memcpy(_start, x._start, x.size() * sizeof(T));//这里的memcpy在用自定义类型时会出事
				_finish = _start + x.size();
				_end_of_storage = _start + x.capacity();
			}
		}*/
		vector(const vector& x)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(x.capacity());
			for (auto& e : x)
			{
				push_back(e);
			}
		}
		//赋值拷贝
		//vector& operator=(vector x)
		vector<T>& operator=(vector<T> x)
		{
			swap(*this, x);
			return *this;
		}
		void push_back(const T&x)
		{
			if (_finish >= _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish++= x;
		}
		void reserve(size_t newcapacity)
		{
			if (newcapacity <= capacity())
			{
				return;
			}
			T* tmp=new T[newcapacity];
			size_t size=this->size();
			if (NULL!=_start)
			{
				//memcpy(tmp, _start, size* sizeof(T));//不要浅拷贝！！！！！！！！！
				//我黑化了，从此不再memcpy
				for(int i=0;i<size;++i)
				{
					*(tmp+i)=*(_start+i);
				}
				delete[]_start;
			}
			_start = tmp;
			_finish = _start + size;
			_end_of_storage = _start + newcapacity;
		}
		T& operator [](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator [](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish >= _end_of_storage)
			{
				size_t i = pos - _start;//扩容后，pos的位置也需要改变
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + i;
			}
			iterator end = _finish++;
			while (end != pos)
			{
				*end = *(end - 1);
				--end;
			}
			*end = x;
			return pos;
		}
		
		//erase
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			--_finish;

			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			return pos;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish++ = val;
				}
			}
		}
		//friend void swap(vector<T>& x1, vector<T>& x2);
		friend void swap(vector<T>& x1, vector<T>& x2)
		{
			std::swap(x1._start, x2._start);
			std::swap(x1._finish, x2._finish);
			std::swap(x1._end_of_storage, x2._end_of_storage);
		}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage=nullptr;//给个缺省值，安全点

	};
	
}