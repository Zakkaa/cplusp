#include<iostream>
using namespace std;

class A
{
public:
	 int _a;
};

class B1 :virtual public A
{
public:
	int _b1;
};
class B2 :virtual public A
{
public:
	int _b2;
};
class C :public B1, public B2
{
public:
	int _d;
};
void Funtest()
{
	B1 b;
	b._a = 10;
}
int main()
{
	Funtest();
	return 0;
}