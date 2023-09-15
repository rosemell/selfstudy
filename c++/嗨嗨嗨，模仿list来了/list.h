#define _CRT_SECURE_NO_WARNINGS 1


#include<assert.h>
#include<iostream>
#include<algorithm>


namespace wda
{



template<class T>
struct list_node
{
public:
	list_node(const T& val=T())
		:_next(nullptr)
		,_prev(nullptr)
		,_val(val)
	{}
	list_node<T>* _next;
	list_node<T>* _prev;
	T _val;
};

template<class T,class Ref,class Pointer>
struct __list_iterator
{
public:
	typedef list_node<T> Node;
	typedef __list_iterator<T, Ref,Pointer> iterator;
	Node* _node;
	__list_iterator()
	{}
	__list_iterator(Node* node)
		:_node(node)
	{}
	~__list_iterator()
	{}
	
	Ref operator*()
	{
		return _node->_val;
	}
	iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	iterator& operator++(int)
	{
		Node* tmp = _node;
		_node = _node->next;
		return __list_iterator(_node);//隐式转换
	}
	iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	iterator& operator--(int)
	{
		Node* tmp = _node;
		_node = _node->prev;
		return __list_iterator(_node);
	}
	bool operator==(const iterator& x)const
	{
		return _node == x._node;
	}
	bool operator!=(const iterator& x)const
	{
		return _node != x._node;
	}
	Pointer operator->()const
	{
		return &_node->_val;
	}
};


template<class T>
class list
{
private:
	typedef list_node<T> Node;
public:
	typedef __list_iterator<T,T&,T*> iterator;
	typedef __list_iterator<T, const T&,const T*>const_iterator;
	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}
	iterator begin()
	{
		return iterator(_head->_next);
		//return _head->_next;//隐式转换
	}
	iterator end()
	{
		return iterator(_head);
	}
	void empty_init()
	{
		_head = new Node;
		_size = 0;
		_head->_next = _head;
		_head->_prev = _head;


	}
	list()
		:_head(new Node)
		,_size(0)
	{
		empty_init();
	}
	list(const list<T>& x)
		:_head(new Node)
		, _size(0)
	{
		empty_init();
		for (auto& e : x)
		{
			push_back(e);
		}
	}
	~list()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
		_size = 0;
	}
	list<T>& operator=(list<T> x)
	{
		swap(x);
		return *this;
	}
	iterator insert(iterator pos,const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);
		newnode->_prev = prev;
		prev->_next = newnode;
		newnode->_next = cur;
		cur->_prev = newnode;
		++_size;
		return newnode;
	}
	iterator erase(iterator pos)
	{
		assert(pos !=end());
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;
		prev->_next = next;
		next->_prev = prev;
		delete cur;
		--_size;
		return next;
	}
	void push_back(const T& x)
	{
		//Node* newnode = new Node(x);
		//Node* tail = _head->_prev;
		//newnode->_next = _head;
		//newnode->_prev = tail;
		//_head->_prev = newnode;
		//tail->_next = newnode;
		insert(end(), x);
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}
	void push_front(const T&x)
	{
		insert(begin(), x);
	}
	void clear()
	{
		iterator it = begin();
		while (it != end())
		{
			it = erase(it);//有点慢了，不用erase会快点
		}
		_size = 0;
	}
	size_t size()
	{
		return _size;
	}
	void swap(list<T> x)
	{
		std::swap(_head, x._head);
		std::swap(_size, x._size);
	}
private:
	Node* _head=nullptr;
	size_t _size=0;
};


}
