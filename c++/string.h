#pragma once
#include<assert.h>
#include<iostream>

namespace wda
{

class string
{
public:
	typedef char* interator;
	typedef const char* const_interator;
	/*string()
		:_size(0)
		,_capacity(10)
		, _str(new char[_capacity + 1])
	{
		_str[0] = '\0';
	}*/
	string(const char* str="")
		:_size(strlen(str))//下方申明顺序最好和初始化顺序保持一致
		, _capacity(_size)//（初始化顺序以申明顺序为准
		,_str(new char[_capacity+1])
	{
		strcpy(_str, str);
	}
	//string(const string& s)
	//	:_size(s._size)
	//	, _capacity(s._capacity)
	//	,_str(new char[s._capacity+1])
	//{
	//	memcpy(_str, s._str, _size+1);
	//}
	string(const string& s)
		:_str(nullptr)//置空,否则可能会delete一个随机地址
	{
		string tmp(s._str);
		swap(tmp);//复用构造函数
	}

	/*string& operator=(const string& s)
	{
		if (this != &s)
		{
			_size = s._size;
			this->reserve(s._capacity);
			memcpy(_str, s._str, _size + 1);
		}
		return *this;
	}*/
	void swap(string& s)//浅交换，但效果一样（效率更高
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	//利用拷贝构造的nb写法
	//string& operator=(const string& s)
	//{
	//	if (this != &s)
	//	{
	//		wda::string tmp(s);
	//		std::swap(_str, tmp._str);
	//		std::swap(_size, tmp._size);
	//		std::swap(_capacity, tmp._capacity);
	//	}
	//	return *this;
	//}
	string& operator=(string tmp)
	{
		swap(tmp);
		return *this;
	}

	~string()
	{
		delete[] _str;
		_size = 0;
		_capacity = 0;
		_str = nullptr;
	}
	const char* c_str()const
	{
		return (const char*)_str;
	}
	int size()const
	{
		return _size;
	}
	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	interator begin()
	{
		return _str;
	}
	interator end()
	{
		return (&_str[0]) + _size;
	}
	const_interator begin()const
	{
		return &_str[0];
	}
	const_interator end()const
	{
		return _str + _size;
	}
	void reserve(size_t n)//n代表字符串长度（不包括'\0'
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//这里好慢啊，感觉不如realloc，但是感觉new更安全一点
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
		
	}
	string& push_back(const char ch)
	{
		if (_size+1 >= _capacity)//扩容
		{
				this->reserve(_capacity==0?10:_capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
	string& append(const char* str)
	{
		size_t len = strlen(str);
		if (_size+len>_capacity)
		{
			this->reserve((_size + len) * 2);
		}
		strcpy(_str + _size, str);
		_size += len;
		return *this;
	}
	string& operator+=(const char ch)
	{
		this->push_back(ch);
		return *this;

	}
	string& operator+=(const char* str)
	{
		this->append(str);
		return *this;
	}
	string& operator+=(const string& str)
	{
		this->append(str.c_str());
		return *this;
		//return append(str.c_str());//这是库的实现方式
	}
	void insert(size_t pos, size_t n, char ch)
	{
		assert(pos <= _size);
		if (_size + n > _capacity)
		{
			reserve((_size+n)*2);
		}
		//挪动数据
		//把原字符串pos位置及之后的字符串往后挪（包括结束位置的'\0'
		//for (int i = _size + n,j=_size,tmp=pos+n-1; i > tmp; --i,--j)
		//{
		//	_str[i] = _str[j];
		//}
		size_t end = _size;
		while (end >= pos && end != _npos)
			//因为end无符号，所以当pos=0时，end会减减为最大，程序就死循环了
		{
			_str[end + n] = _str[end];
			--end;
		}
		//size_t end = _size+n;
		//size_t begin = pos + n;//pos和n不能同时为0
		//while (end >= begin)
		//{
		//	_str[end] = _str[end - n];
		//	--end;
		//}

		//for (int i = pos,tmp=pos+n; i < tmp; ++i)//感觉这么写有点虎
		//{
		//	_str[i] = ch;
		//}
		for (size_t i = 0; i < n; ++i)//这样的话更好看一点，但每个循环多一次计算
		{
			_str[i + pos] = ch;
		}
		_size += n;
	}
	void insert(size_t pos,const char*str)
	{
		assert(pos < _size);
		size_t len=strlen(str);
		if (_size + len > _capacity)
		{
			reserve((_size + len)*2);
		}
		size_t end = _size;
		while (end >= pos && end != _npos)
		{
			_str[end + len] = _str[end];
			--end;
		}
		for (size_t i = 0; i < len; ++i)
		{
			_str[i + pos] = str[i];
		}
		_size += len;
	}
	void erase(size_t pos,size_t len=_npos)
	{
		assert(pos <= _size);
		if ((long long)pos+len >= _size)//删到字符串末尾
			//当len=_npos时容易溢出，所以强制转换下类型
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			for (size_t begin = pos; begin+len<=_size; ++begin)
			{
				_str[begin] = _str[begin + len];
			}
			_size -= len;
		}
	}
	size_t find(char ch, size_t pos = 0)
	{
		assert(pos < _size);
		for (int i=pos;i<_size;++i)
		{
			if (_str[i]==ch)
			{
				return i;
			}
		}
		return _npos;
	}
	size_t find(const char*str, size_t pos = 0)
	{
		assert(pos < _size);
		int end = _size - strlen(str);
		//for (int i = pos; i <= end; ++i)
		//{
		//	if (0 == strcmp(_str + i, str))
		//	{
		//		return i;
		//	}
		//}
		//return _npos;
		char* ptr = strstr(_str + pos, str);
		if (ptr != 0)
		{
			return ptr - _str;
		}
		else
		{
			return _npos;
		}
	}
	void resize(size_t size,char ch='\0')
	{
		assert(size <= _size);
		if (size > _capacity)
		{
			reserve(size);
		}
		if (size > _size)
		{
			for (; size > _size; _size++)
			{
				_str[_size] = ch;
			}
		}
		else
		{
			_size = size;
		}
		_str[_size] = '\0';
	}
	wda::string substr(size_t pos = 0, size_t len = _npos)
	{
		assert(pos < _size);
		if ((pos + len >= _size) || len == _npos)
		{
			return string(_str + pos);
		}
		else
		{
			string tmp;
			tmp.reserve(len * 2);

			for (int i = 0; i < len; ++i)
			{
				tmp += _str + pos + i;
			}
			return tmp;
		}
	}
	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
	int operator>(const string& s)const
	{
		int i = 0;
		while(_str[i]==s._str[i])
		{
			++i;
			if (i == s._size || i == _size)
			{
				//hello           hello      return false
				//hello           helloxxx   return false
				//helloxxx        hello      return true
				return _size > s._size;
			}
		}
		return _str[i] > s._str[i];
	}
	int operator<(const string& s)const
	{

		bool ret = memcpy(s._str, _str, _size < s._size ? _size : s._size);		

		return ret > 0 ? s._size>_size: ret;
	}
	int operator==(const string& s)const
	{
		return _size == s._size 
			&& memcpy(_str, s._str, _size < s._size ? _size : s._size) == 0;
	}
	int operator>=(const string& s)const
	{
		return !(*this < s);
	}
private:
	size_t _size;//字符串长度
	size_t _capacity;//_str指向空间的大小-1（多出来的1字节用于存放'\0'
	char* _str;
	//const static size_t _npos = -1;
	//const static 整形类型 可以声明和定义不分离
	//const static double x = 1.1;
	//double就不行，逆天语法
	const static size_t _npos;
};
	const size_t wda::string::_npos = -1;
};

std::ostream& operator<<(std::ostream& out, const wda::string& str)
{
	for (auto ch : str)
	{
		out<<ch;
	}
	return out;
}
std::istream& operator>>(std::istream& in, wda::string& str)
{
	str.clear();
	char ch;
	while(str.size()==0)
	{
		ch = in.get();
		while (ch != '\n' && ch != ' ')
		{
			str += ch;
			ch = in.get();
		}
	}
	return in;
}

//
////有缓存版（用于防止str持续扩容，个人感觉用处不大
//std::istream& operator>>(std::istream& in, wda::string& str)
//{
//	str.clear();
//	char ch;
//	ch = in.get();
//	while (ch == ' ' || ch == '\n')
//	{
//		ch = in.get();
//	}
//	const static int cap = 128;
//	char buff[cap];
//	int i = 0;
//	while (ch != '\n' && ch != ' ')
//	{
//		buff[i++] = ch;
//		if (i == cap-1)
//		{
//			buff[i] = '\0';
//			i = 0;
//			str += buff;
//		}
//		ch = in.get();
//	}
//	if (i != 0)
//	{
//		buff[i] = '\0';
//		str += buff;
//	}
//	return in;
//}

