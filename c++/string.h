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
		:_size(strlen(str))//�·�����˳����úͳ�ʼ��˳�򱣳�һ��
		, _capacity(_size)//����ʼ��˳��������˳��Ϊ׼
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
		:_str(nullptr)//�ÿ�,������ܻ�deleteһ�������ַ
	{
		string tmp(s._str);
		swap(tmp);//���ù��캯��
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
	void swap(string& s)//ǳ��������Ч��һ����Ч�ʸ���
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	//���ÿ��������nbд��
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
	void reserve(size_t n)//n�����ַ������ȣ�������'\0'
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//������������о�����realloc�����Ǹо�new����ȫһ��
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
		
	}
	string& push_back(const char ch)
	{
		if (_size+1 >= _capacity)//����
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
		//return append(str.c_str());//���ǿ��ʵ�ַ�ʽ
	}
	void insert(size_t pos, size_t n, char ch)
	{
		assert(pos <= _size);
		if (_size + n > _capacity)
		{
			reserve((_size+n)*2);
		}
		//Ų������
		//��ԭ�ַ���posλ�ü�֮����ַ�������Ų����������λ�õ�'\0'
		//for (int i = _size + n,j=_size,tmp=pos+n-1; i > tmp; --i,--j)
		//{
		//	_str[i] = _str[j];
		//}
		size_t end = _size;
		while (end >= pos && end != _npos)
			//��Ϊend�޷��ţ����Ե�pos=0ʱ��end�����Ϊ��󣬳������ѭ����
		{
			_str[end + n] = _str[end];
			--end;
		}
		//size_t end = _size+n;
		//size_t begin = pos + n;//pos��n����ͬʱΪ0
		//while (end >= begin)
		//{
		//	_str[end] = _str[end - n];
		//	--end;
		//}

		//for (int i = pos,tmp=pos+n; i < tmp; ++i)//�о���ôд�е㻢
		//{
		//	_str[i] = ch;
		//}
		for (size_t i = 0; i < n; ++i)//�����Ļ����ÿ�һ�㣬��ÿ��ѭ����һ�μ���
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
		if ((long long)pos+len >= _size)//ɾ���ַ���ĩβ
			//��len=_nposʱ�������������ǿ��ת��������
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
	size_t _size;//�ַ�������
	size_t _capacity;//_strָ��ռ�Ĵ�С-1���������1�ֽ����ڴ��'\0'
	char* _str;
	//const static size_t _npos = -1;
	//const static �������� ���������Ͷ��岻����
	//const static double x = 1.1;
	//double�Ͳ��У������﷨
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
////�л���棨���ڷ�ֹstr�������ݣ����˸о��ô�����
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

