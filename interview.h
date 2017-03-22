#pragma once
#include <iostream>
using namespace std;

//1. 实现一个栈，要求实现Push（出栈）、Pop（入栈）、Min（返回最小值的操作）的时间复杂度为O(1)
#include <vector>
template<class T>
class Stack
{
public:
	void Push(const T& data)
	{
		_v.push_back(data);
		if (!_min.empty())
		{
			if (data <= *(_min.end()-1))
			{
				_min.push_back(data);
			}
		}
		else
			_min.push_back(data);
	}
	void Pop()
	{
		if (*(_v.end() - 1) == *(_min.end() - 1))
			_min.pop_back();
		_v.pop_back();
	}

	T Min()
	{
		return *(_min.end() - 1);
	}
private:
	vector<T> _v;
	vector<T> _min;
};
void StackTest()
{
	Stack<int> s1;
	s1.Push(10);
	s1.Push(8);
	s1.Push(9);
	s1.Push(0);
	s1.Push(0);
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
}
//2. 使用两个栈实现一个队列
#include <stack>
template<typename T>
class Queue
{
public:
	void Push(const T& data)
	{
		_s1.push(data);
	}
	void Pop()
	{
		while (!_s1.empty())
		{
			_s2.push(_s1.top());
			_s1.pop();
		}
		cout << _s2.top() << " ";
		_s2.pop();
		while (!_s2.empty())
		{
			_s1.push(_s2.top());
			_s2.pop();
		}
	}

private:
	stack<T> _s1;
	stack<T> _s2;
};
void QueueTest()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
}
//3. 使用两个队列实现一个栈
#include<queue>
template<typename T>
class StackBQ
{
public:
	void Push(const T& data)
	{
		_q1.push(data);
	}
	void Pop()
	{
		while ((_q1.size()--) == 1)
		{
			_q2.push(_q1.front());
			_q1.pop();
		}
		_q1.pop();
		_q1.swap(_q2);
	}
	void Top()
	{
		return _q1.back();
	}
private:
	queue<T> _q1;
	queue<T> _q2;
};
//4. 元素出栈、入栈顺序的合法性。如入栈的序列（1, 2, 3, 4, 5），出栈序列为（4, 5, 3, 2, 1）
template<typename T>
bool Islegal(const T* a,const T* b,size_t size)
{
	stack s;
	for (size_t index = 0; index < size; index++)
	{
		s.push(a[index]);
	}
	for (size_t index = 0; index < size; index++)
	{
		if (s.top() != b[index])
			return false;
		s.pop();
	}
	return true;
}
//5. 一个数组实现两个栈
//一个数组实现两个栈
template<class T>
class TwoStack
{
public:
	TwoStack()
		:_a(NULL)
		, _top1(0)
		, _top2(0)
		, _capacity(0)
	{
		_CheckCapacity();
	}
	~TwoStack()
	{
		if (_a)
			delete[] _a;
	}
	void Push1(const T& d)
	{
		_CheckCapacity();
		_a[_top1++] = d;
	}
	void Push2(const T& d)
	{
		_CheckCapacity();
		_a[_top2--] = d;
	}
	void Pop1()
	{
		if (_top1 > 0)
			--_top1;
	}
	void Pop2()
	{
		if (_top2 < _capacity - 1)
			_top2++;
	}
	size_t Size1()
	{
		return _top1;
	}
	size_t Size2()
	{
		return _capacity - 1 - _top2;
	}
	bool Empty1()
	{
		return _top1 == 0;
	}
	bool Empty2()
	{
		return _top2 == _capacity - 1;
	}
	T& Top1()
	{
		if (_top1>0)
		{
			return _a[_top1 - 1];
		}
	}
	T& Top2()
	{
		if (_top2 < _capacity - 1)
			return _a[_top2 + 1];
	}

private:
	void _CheckCapacity()
	{
		if (_a == NULL)
		{
			_capacity += 3;
			_a = new T[_capacity];
			_top2 = _capacity - 1;
			return;
		}
		if (_top1 == _top2)
		{
			size_t OldCapacity = _capacity;
			_capacity = _capacity * 2;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < _top1; i++)
			{
				tmp[i] = _a[i];
			}
			for (size_t j = OldCapacity - 1, i = _capacity - 1; j>_top2; j--, i--)
			{
				tmp[i] = _a[j];
			}
			delete[] _a;
			_a = tmp;
			_top2 += _capacity / 2;
		}
	}

private:
	T* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
};