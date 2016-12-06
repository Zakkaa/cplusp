#include<iostream>
#include<time.h>
using namespace std;
class CInt
{
	friend ostream& operator<<(ostream& _cout, const CInt& I);
	friend istream& operator>>(istream& _cin, CInt& I);
public:
	CInt& operator=(const CInt& I)
	{
		if (this!=&I)
		{
			_value = I._value;
		}
		return *this;
	}
	CInt operator+(const CInt& I)
	{
		CInt temp(I);
		temp._value = _value + I._value;
		return temp;
	}
	CInt operator-(const CInt& I)
	{
		CInt temp(I);
		temp._value = _value - I._value;
		return temp;
	}
	CInt operator*(const CInt& I)
	{
		CInt temp(I);
		temp._value = _value * I._value;
		return temp;
	}
	CInt operator/(const CInt& I)
	{
		CInt temp(I);
		if (I._value != 0)
		{
			temp._value = _value * I._value;
		}
		return temp;
	}
	bool operator==(const CInt& I)
	{
		return (_value == I._value);
	}
	bool operator!=(const CInt& I)
	{
		return (_value != I._value);
	}
	bool operator>(const CInt& I)
	{
		return (_value > I._value);
	}
	bool operator<(const CInt& I)
	{
		return (_value < I._value);
	}
	bool operator>=(const CInt& I)
	{
		return (_value >= I._value);
	}
	bool operator<=(const CInt& I)
	{
		return (_value <= I._value);
	}
	bool operator||(const CInt& I)
	{
		return (_value || I._value);
	}
	bool operator&&(const CInt& I)
	{
		return (_value && I._value);
	}
	CInt& operator++()//Ç°ÖÃ++
	{
		++_value;
		return *this;
	}
	CInt operator++(int)//ºóÖÃ++
	{
		CInt temp(*this);
		++_value;
		return temp;
	}
	CInt& operator--()
	{
		--_value;
		return *this;
	}
	CInt operator--(int)
	{
		CInt temp(*this);
		--_value;
		return temp;
	}
private:
	int _value;
};

ostream& operator<<(ostream& _cout, const CInt& I)
{
	_cout << I._value;
	return _cout;
}
istream& operator>>(istream& _cin, CInt& I)
{
	cin >> I._value;
	return _cin;
}


class CMyCountTime
{
private:
	clock_t m_time;
public:
	CMyCountTime(){ m_time = clock(); }
	~CMyCountTime()
	{
		m_time = clock() - m_time;
		cout << m_time << endl;
	}
};