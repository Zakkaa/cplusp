#include<iostream>
using namespace std;


//�°��µ�auto_ptr,ȱ�㣺һ��ռ�ֻ����һ��ָ�����
template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* p = NULL)
		:_p(p)
	{}
	~AutoPtr()
	{
		if (NULL != _p)
		{
			delete _p;
			_p = NULL;
		}
	}
	AutoPtr(AutoPtr<T> & ap)
		:_p(ap._p)
	{
		ap._p = NULLL;
	}
	AutoPtr<T> & operator=(AutoPtr<T> & ap)
	{
		_p = ap._p;
		ap._p = NULL;
		return *this;	
	}
private:
	T* _p;
};

//ScopedPtr  ʹ�ó�����һ���ռ�ֻ��Ҫһ��ָ��ȥ�����ʱ��

template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* p = NULL)
		:_p(p)
	{}
	~ScopedPtr()
	{
		if (NULL != _p)
		{
			delete _p;
			_p = NULL;
		}
	}
private:
	ScopedPtr(ScopedPtr<T>& ap);
	ScopedPtr<T>& operator=(ScopedPtr<T> &ap);
private:
	T* _p;
};

//SharedPtr
template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* p = NULL)
		:_p(p),
		_pCount(NULL)
	{
		if (_p != NULL)
		{
			_pCount = new(int(1));
		}
	}
	~SharedPtr()
	{
		if (_pCount && 0 == --(*_pCount))
		{
			delete _p;
			delete _pCount;
			_p = NULL;
			_pCount = NULL;
		}
	}
	SharedPtr(SharedPtr<int> &ap)
		:_p(ap._p),
		_pCount(ap._pCount)
	{
		if (_pCount)
		{
			(*_pCount)++;
		}
	}
	SharedPtr<T>&operator=(SharedPtr<T>& ap)
	{
		if (_p != ap._p)
		{
			if (NULL == _p)
			{
				_p = ap._p;
				_pCount = ap._pCount;
			}
			else if (1 == (*_pCount))
			{
				delete _p;
				delete _pCount;
				_p = ap._p;
				_pCount = ap._pCount;
			}
			else
			{
				--(*_pCount);
				_p = ap._p;
				_pCount = ap._pCount;
			}
		}
		if (__pCount~= NULL)
		{
			*_pCount++;
		}
	}

private:
	T* _p;
	int* _pCount;
};


//void AutoTest()
//{
//	AutoPtr<int> ap1 = new(int);
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int>ap3;
//	ap3 = ap1;
//}

//void ScopedTest()
//{
//	ScopedPtr<int> ap1 = new(int);
//	//ScopedPtr<int>ap2(ap1);
//}


int main()
{
	//AutoTest();
	//ScopedTest();
	return 0;
}
