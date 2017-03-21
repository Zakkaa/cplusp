#include<iostream>
using namespace std;
#include<assert.h>
#define DataType int

struct Node   //节点
{
	Node(const DataType & data = 0)
	:_pNext(NULL)
	, _pPre(NULL)
	{}
	Node* _pNext;
	Node* _pPre;
	DataType _data;
}; 

class List //链表类
{
	friend ostream& operator<<(ostream& _count, const List&l);
public:
	List()  //构造
		:_pHead(NULL)
		, _pTail(NULL)
		, _size(0)
	{}
	List(DataType arr[], size_t size)  //有初始值的构造
	{
		for (size_t idx = 0; idx<size; ++idx)
		{
			PushBack(arr[idx]);
		}
	}
	List(const List& l)  //拷贝
		:_size(0)
	{
		Node* pCurNode = l ._pHead;
		while (pCurNode)
		{
			PushBack(pCurNode->_data);
			pCurNode = pCurNode->_pNext;
		}
	}
	List& operator=(const List& l)
	{
		if (this != &l)
		{
			Node*temp = _pHead;
			_pHead->_pPre = NULL;
			Node*CurNode = l._pHead;
			while (CurNode)
			{
				temp = CurNode;
				CurNode = CurNode->_pNext;
				temp = temp->_pNext;
				_size++;
			}
			temp->_pNext = NULL;
		}
	}
	~List()
	{
		if (NULL != this)
		{
			Node* pDel = _pHead;
			Node* pCur = _pHead->_pNext;
			while (pCur ->_pNext)
			{
				pCur = pCur->_pNext;
				pDel = pCur->_pPre;
				delete pDel ;
			}
			delete pCur ;
			_pTail = NULL;
			pDel = _pHead;
			delete pDel;
			_pHead = NULL;
			_size = 0;
		}
	}

	void PushBack(const DataType& data)
	{
		if (NULL == _pHead)
		{
			_pHead = _pTail = _BuyNode(data);
		}
		else
		{
			Node* pNewNode = _BuyNode(data);
			_pTail->_pNext = pNewNode;
			pNewNode->_pPre = _pTail;
			_pTail = pNewNode;
		}
		_size++;
	}
	void PopBack()
	{
		if (Empty())
		{
			assert(false);
			return;
		}
		if (_pHead == _pTail)
		{
			delete _pHead;
			_pHead = _pTail = NULL;
		}
		else
		{
			//
		}
	}
	bool Empty()
	{
		return NULL == _pHead;
	}
	void PushFront(const DataType data)
	{
		if (NULL == _pHead)
		{
			_pHead = _pTail = _BuyNode(data);
		}
		else
		{
			Node* pNewNode = _BuyNode(data);
			pNewNode->_pNext = _pHead;
			_pHead->_pPre = pNewNode;
			_pHead = pNewNode;
		}
	}
	void Insert(Node* pos, DataType data)
	{
		Node* pNewNode = new Node(data);
		pNewNode->_pNext = pos->_pNext;
		pNewNode->_pPre = pos;
		pos->_pNext = pNewNode;
		if (NULL != pNewNode->_pNext)
		{
			pNewNode->_pNext->_pPre = pNewNode;
		}
		else
		{
			pNewNode->_pNext = NULL;
		}
	}
	void Erase(Node* pos)
	{
		if (Empty())
		{
			return;
		}
		if (NULL == pos->_pNext)
		{
			pos->_pPre->_pNext = NULL;
			delete (pos);
		}
		else
		{

		}
		pos->_pNext->_pPre = pos->_pPre;
		pos->_pPre->_pNext = pos->_pNext;
	}
private:
	Node* _BuyNode(const DataType& data)
	{
		return ((Node*)new Node(data));
	}
private:
	Node* _pHead;
	Node* _pTail;
	size_t _size;
};