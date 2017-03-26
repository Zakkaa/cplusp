#include<iostream>
using namespace std;
#include<assert.h>
char *arr[] = { "int", "double", "float", "char", "long" };//定义内置类型
bool CheckPODType(const char* TypeName)
{
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (strcmp(arr[i], TypeName) == 0)
		{
			return true;
		}
	}
	return false;
}
bool CheckPODType(const char* TypeName);
template<typename T>
class Vector
{
public:
	Vector();
	Vector(const T arr[], size_t size);
	Vector(const Vector& v);
	Vector& operator=(const Vector& s);
	~Vector();
public:
	void PushBack(const T& data);
	void PopBack();
	void Insert(size_t pos, const T& data);
	void Erase(size_t pos);
	const T& operator[](size_t index)const;
	T& operator[](size_t index);
	T& Front();
	const T& Front()const;
	T& Back();
	const T& Back()const;
	bool Empty()const;
	size_t Size()const;
	size_t Capacity()const;
	void Clear();
	void Resize(size_t size);
private:
	void _CheckCapacity();
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};
template<typename T>
Vector<T>::Vector()
:_pData(new T[3])
, _size(0)
, _capacity(3)
{}
template<typename T>
Vector<T>::Vector(const T arr[], size_t size)
: _size(size)
, _capacity(size)
, _pData(new T[size])
{
	if (arr != NULL)
	{
		memcpy(_pData, arr, size*sizeof(T));
	}
}
template<typename T>
Vector<T>::Vector(const Vector& v)
: _size(v._size)
, _capacity(v._capacity)
, _pData(new T[v._capacity])
{
	memcpy(_pData, v._pData, v._size*sizeof(T));
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v)
{
	if (this != &v)
	{
		T* tmp = new T[v._capacity];
		if (CheckPODType(typeid(T).name()))
		{
			memcpy(tmp, v._pData, v._size*sizeof(T));
		}
		else
		{
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = v._pData[i];
			}
		}
		delete[] _pData;
		_pData = tmp;
		_size = v._size;
		_capacity = v._capacity;
	}
	return *this;
}
template<typename T>
Vector<T>::~Vector()
{
	if (this != NULL)
	{
		delete[] _pData;
		_pData = NULL;
		_size = 0;
		_capacity = 0;
	}
}
template<typename T>
void Vector<T>::PushBack(const T &data)
{
	CheckCapacity();
	_pData[_size++] = data;
}
template<typename T>
void Vector<T>::PopBack()
{
	if (Empty())
	{
		assert(false);
		return;
	}
	_size--;
}
template<typename T>
bool Vector<T>::Empty()
{
	if (_size == 0)
		return true;
	else
		return false;
}
template<typename T>
void Vector<T>::Insert(size_t pos, const T& data)
{
	assert(pos<_size);
	CheckCapacity();
	for (size_t i = _size; i>pos; i--)
	{
		_pData[i] = _pData[i - 1];
	}
	_pData[pos] = data;
	_size++;
}
template<typename T>
void Vector<T>::Erase(size_t pos)
{
	assert(pos<_size);
	for (size_t i = pos; i<_size - 1; i++)
	{
		_pData[i] = _pData[i + 1];
	}
	_size--;
}
template<typename T>
const T& Vector<T>::operator[](size_t index)const
{
	assert(index<_size);
	return _pData[index];
}
template<typename T>
T& Vector<T>::operator[](size_t index)
{
	assert(index<_size);
	return _pData[index];
}
template<typename T>
T& Vector<T>::Front()
{
	return _pData[0];
}
template<typename T>
const T& Vector<T>::Front()const
{
	return _pData[0];
}
template<typename T>
T& Vector<T>::Back()
{
	return _pData[_size - 1];
}
template<typename T>
const T& Vector<T>::Back()const
{
	return _pData[_size - 1];
}
template<typename T>
size_t Vector<T>::Size()const
{
	return _size;
}
template<typename T>
size_t Vector<T>::Capacity()const
{
	return _capacity;
}
template<typename T>
void Vector<T>::Clear()
{
	_size = 0;
}
template<typename T>
void Vector<T>::Resize(size_t size)
{
	if (size == _size)
	{
		return;
	}
	else if (size < _size)
	{
		_size = size;
	}
	else
	{
		size_t oldsize = _size;
		_size = size;
		CheckCapacity();
	}
}