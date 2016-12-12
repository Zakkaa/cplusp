#pragma once 
#include<iostream>
using namespace std;
#include<assert.h>

enum Type
{
	HEAD,		//头结点类型
	VALUE,		//数据类型
	SUB			//子表类型
};

struct GeneralizedNode
{
	Type _type;
	GeneralizedNode* _next;
	union                     //每个节点都有类型及指向下一个节点的指针，数据和字表首地址只会拥有其一				
	{
		char _value;
		GeneralizedNode* _subLink;
	};
	GeneralizedNode(Type type, char value=0)
		:_type(type)
		, _next(NULL)
	{
		if (type == VALUE)
		{
			_value = value;
		}
		else if (type == SUB)
		{
			_subLink = NULL;
		}
	}
};

class Generalized
{
	typedef GeneralizedNode Node;
public:
	Generalized()
		:_head(NULL)
	{}
	Generalized(const char *s)
		:_head(NULL)
	{
		_head = _CreateList(s);
	}
	Generalized(const Generalized& g)
	{
		_head = _Copy(g._head);
	}
	Generalized& operator= (const Generalized& g)
	{
		if (this != &g)
		{
			Node*tmp = _Copy(g._head);
			_Destroy(_head);
			_head = tmp;
		}
	}
	~Generalized()
	{
		_Destroy(_head);
	}
	void Print()
	{
		_Print(_head);
	}
	size_t Size()
	{
		return _size(this->_head);
	}
protected:
	void _Print(Node* head)
	{
		assert(head);
		cout << '(';
		while (head)
		{
			if (head->_type == VALUE)
			{
				cout << head->_value;
				if (head->_next)
				{
					cout << ',';
				}
			}
			else if(head->_type == SUB)
			{
				_Print(head->_subLink);
				if (head->_next)
				{
					cout << ',';
				}
			}
			head = head->_next;
		}
		if (head == NULL)
			cout << ')';

	}
	bool IsValue(char ch)
	{
		if (ch >= '0'&&ch <= '9' || ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			return true;
		else return false;
	}
	Node* _CreateList(const char*& s)
	{
		assert(*s == '(');
		s++;
		Node* head = new Node(HEAD);
		Node* tail = head;
		while (*s!=')')
		{
			if (IsValue(*s))
			{
				tail->_next = new Node(VALUE, *s);
				tail = tail->_next;
				++s;
			}
			else if (*s == '(')
			{
				tail->_next = new Node(SUB);
				tail = tail->_next;
				tail->_subLink = _CreateList(s)->_next;
				s++;
			}
			else ++s;
		}
		return head;
	}
	Node* _Copy(Node* head)
	{
		Node* Cur = head;
		Node* newhead = new Node(HEAD);
		Node* tail = newhead;
		while (Cur)
		{
			if (Cur->_value == VALUE)
			{
				tail->_next = new Node(VALUE, Cur->_value);
				tail = tail->_next;
			}
			else if (Cur->_value == SUB)
			{
				tail->_next = new Node(SUB);
				tail = tail->_next;
				tail->_subLink = _Copy(Cur->_subLink);
			}
			else assert(false);
			Cur = Cur->_next;
		}
		return newhead;
	}
	void _Destroy(Node* head)
	{
		Node* cur = head;
		while (head)
		{
			if (cur->_type != SUB)
			{
				cur = cur->_next;
				delete head;
				head = cur;
			}
			else
			{
				_Destroy(head->_subLink);
				cur = cur->_next;
				delete head;
				head = cur;
			}
		}
	}
	size_t _size(Node* head)
	{
		size_t count = 0;
		Node* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				count++;
			}
			else if (cur->_type == SUB)
			{
				count += _size(cur->_subLink);
			}
			cur = cur->_next;
		}
		return count;
	}
protected:
	Node* _head;
};


void Test()
{
	Generalized g1("(1, 2, 3,(4), 5)");
	//g1.Print();
	cout<<g1.Size();
}