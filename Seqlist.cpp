#include<iostream>
using namespace std;
#define DataType int
#include<assert.h>


class SeqList
{
public:
	SeqList()//构造函数
		:_pData(new DataType[3])
		, _size(0)
		, _capacity(3)
	{}
	SeqList(DataType arr[], size_t size)//初始值构造函数
		:_size(size)
		, _capacity(size)
		, _pData(new DataType[size])
	{
		for (size_t idx = 0; idx < size; idx++)
		{
			_pData[idx] = arr[idx];
		}
	}
	SeqList(const SeqList& s) //拷贝构造
		:_size(s._size)
		, _capacity(s._capacity)
		, _pData(new DataType[s._capacity*sizeof(DataType)])
	{
		for (size_t idx = 0; idx < s._size; idx++)
		{
			_pData[idx] = s._pData[idx];
		}
	}
	/*SeqList& operator = (const SeqList& s)
	{
		if (this != &s)
		{
			DataType *pTemp = new DataType[s._size];
			for (size_t idx = 0; idx < s._size; idx++)
			{
				pTemp[idx] = s._pData[idx];
			}
			delete[] _pData;
			_pData = pTemp;
			_size = s._size;
		}
		return *this;

	}*/
	SeqList& operator=(SeqList s)//赋值运算符重载->简洁版
	{
		swap(_pData, s._pData);
		_size = s._size;
		return *this;
	}

	~SeqList()
	{
		delete[] _pData;
		_pData = NULL;
		_size = 0;
		_capacity = 0;
	}

	void PushBack(const DataType& data)
	{
		_CheckCapacity();
		_pData[_size] = data;
		++_size;
	}

	void PopBack()
	{
		if (Empty())
		{
			assert(false);
			return;
		}
		--_size;
	}
	void Insert(size_t pos, const DataType& data)
	{
		assert(pos < _size);
		_CheckCapacity();
		for (size_t idx = _size; idx>pos; idx--)
		{
			_pData[idx] = _pData[idx - 1];
		}
		_pData[pos] = data;
		++_size;
	}
	void Erase(size_t pos)
	{
		assert(Empty() == 0);
		for (size_t idx = pos; idx < _size - 1; idx++)
		{
			_pData[idx] = _pData[idx + 1];
		}
		--_size;
	}
	int Find(const DataType& data)const
	{
		for (size_t idx = 0; idx < _size; idx++)
		{
			if (_pData[idx] == data)
				return idx;
		}
		return -1;
	}
	size_t Size()const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _size;
	}
	DataType& operator[](size_t index)
	{
		assert(index < _size);
		return _pData[index];
	}

	// 返回首元素
	DataType& Front()
	{
		return _pData[0];
	}
	DataType& Front()const
	{
		return _pData[0];
	}
	DataType& Back()
	{
		return _pData[_size - 1];
	}
	const DataType& Back()const
	{
		return _pData[_size - 1];
	}
	const DataType& operator[](size_t index)const
	{
		assert(index < _size);
		return _pData[index];
	}
	bool Empty()const
	{
		return (0 == _size);
	}
	void Clear()
	{
		delete[] _pData;
		_pData == NULL;
		_size == 0;
		_capacity = 0;
	}
	void Resize(size_t size, const DataType& data = 0)
	{
		if (size < _size)
		{
			_size = size;
		}
		else if (size> _size)
		{
			size_t oldsize = _size;
			_size = size;
			_CheckCapacity();
			for (int idx = oldsize; idx < _size; idx++)
			{
				_pData[idx] = data;
			}
		}
	}
	void Print()
	{
		for (size_t idx = 0; idx < _size; idx++)
		{
			cout<<_pData[idx]<<"->";
		}
		cout << "NULL";
	}
private:
	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			DataType* pTemp = new DataType[_capacity * 2];
			for (size_t idx = 0; idx < _size; idx++)
			{
				pTemp[idx] = _pData[idx];
			}
			delete[] _pData;
			_pData = pTemp;
			_capacity = _capacity * 2;
		}
	}
private:
	DataType* _pData;
	size_t _size;
	size_t _capacity;
};

void TestFun()
{
	SeqList s1;
	int arr[3] = {1,2,3};
	SeqList s2(arr, 3);
	SeqList s3(s2);
	s1 = s3;
}

void TestFun2()
{
	SeqList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.Insert(2, 5);
	s1.Erase(s1.Find(1));
	s1.Print();
	cout << s1.Size() << s1[2];
}

int main()
{
	TestFun2();
	return 0;
}