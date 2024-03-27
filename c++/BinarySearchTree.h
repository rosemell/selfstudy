#pragma once
#include<iostream>
namespace wda {

	template<class K>
	struct BSTreeNode
	{
	public:
		BSTreeNode()
			:_left(nullptr)
			, _right(nullptr)
		{}
		BSTreeNode(const K& x)
			:_key(x)
			, _left(nullptr)
			, _right(nullptr)
		{}

		K _key;
		BSTreeNode* _left;
		BSTreeNode* _right;
	};


	template<class K>
	class BSTree
	{
	public:
		typedef BSTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}

		~BSTree()
		{
			Destroy(_root);
		}
		BSTree(const BSTree<K>& x)
		{
			_root = copy(x._root);
		}

		//BSTree(const BSTree<K>& x)
		//{
		//	_BSTree(_root, x._root);
		//}
		//void _BSTree(Node*& root1, const Node*const&root2)
		//{

		//	if (nullptr == root2)
		//		return;
		//	root1 = new Node(root2->_key);
		//	_BSTree(root1->_left, root2->_left);
		//	_BSTree(root1->_right, root2->_right);
		//}


		bool My_Shit_Insert(const K& key)
		{
			if (nullptr == _root)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			while (key != cur->_key)
			{
				if (key < cur->_key)
				{
					if (nullptr == cur->_left)
					{
						cur->_left = new Node(key);
						return true;
					}
					else
					{
						cur = cur->_left;
					}
				}
				else//此时key-> _key >cur->k
				{
					if (nullptr == cur->_right)
					{
						cur->_right = new Node(key);
						return true;
					}
					else
					{
						cur = cur->_right;
					}
				}
			}
			return false;
		}

		void _InOrder(const Node* root)const//其实名字不做区分也可以，两函数构成重载
		{
			if (nullptr == root)
				return;
			_InOrder(root->_left);
			std::cout << root->_key << " ";
			_InOrder(root->_right);

		}
		void InOrder()const
		{
			_InOrder(_root);
			std::cout << "\n";
		}
		bool Insert(const K& key)
		{
			if (nullptr == _root)
			{
				_root = new Node(key);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			if (key < parent->_key)
			{
				parent->_left = new Node(key);
			}
			else
			{
				parent->_right = new Node(key);
			}
			return true;
		}


		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}



		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else//找到目标节点
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)//等价于parent判空
						{
							_root = cur->_right;
						}
						else
						{
							if (key < parent->_key)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (key < parent->_key)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
					}
					else//说明被删节点两边都有子节点
					{
						Node* RParent = cur;
						Node* Right_Min = cur->_right;
						while (Right_Min->_left)
						{
							RParent = Right_Min;
							Right_Min = Right_Min->_left;
						}
						cur->_key = Right_Min->_key;

						if (RParent == cur)
						{
							RParent->_right = nullptr;
						}
						else
						{
							RParent->_left = nullptr;
						}
						cur=Right_Min;
					}
					delete cur;
					return true;
				}
			}
			return false;
		}
		BSTree<K>& operator=(BSTree<K>x)
		{
			std::swap(_root,x._root);
			return *this;
		}

		bool FindR(const K& key)
		{
			return _Find(_root, key);
		}
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	private:
		Node* copy(Node* root)
		{
			if (nullptr == root)
				return nullptr;
			Node* copyroot = new Node(root->_key);
			copyroot->_left = copy(root->_left);
			copyroot->_right = copy(root->_right);
			return copyroot;
		}
		void Destroy(Node*& root)
		{
			if (nullptr == root)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}
		bool _EraseR(Node*& root, const K& key)
		{
			if (nullptr == root)
			{
				return false;
			}
			if (key < root->_key)
			{
				return _EraseR(root->_left, key);
			}
			else if (key > root->_key)
			{
				return _EraseR(root->_right, key);
			}
			else//相等，准备删除
			{
				Node* cur = root;//待删节点
				//先找到替代节点
				if (nullptr == root->_left)
				{
					root = root->_right;
				}
				else if (nullptr == root->_right)
				{
					root = root->_left;
				}
				else//待删两边都有节点
				{
					cur = root->_right;//找到右子树的最小节点或左子树的最大节点
					while (cur->_left)
					{
						cur = cur->_left;
					}
					std::swap(root->_key, cur->_key);
					if (cur == root->_right)
					{
						root->_right = nullptr;
					}
					else
					{
						root->_left = nullptr;
					}
					//_EraseR(root->_right,key);//...感觉一点也不稳
				}
				delete cur;
				return true;
			}
			return false;
		}
		bool _InsertR(Node*& root,const K& key)
		{
			if (nullptr == root)
			{
				root = new Node(key);
				return true;
			}
			if (key < root->_key)
			{
				return _InsertR(root->_left, key);
			}
			else if (key > root->_key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		bool _FindR(Node* root, const K& key)
		{
			if (nullptr == root)
			{
				return false;
			}
			if (key < root->_key)
			{
				return _FindR(root->_left, key);
			}
			else if(key > root->_key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}

	private:
		Node* _root;
	};


}
