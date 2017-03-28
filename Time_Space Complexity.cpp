#include<iostream>
using namespace std;


//递归版二分法查找
//时间复杂度：O(Log2X)
//空间复杂度：0(Log2X)
int Binary1(int array[],int key,int left,int right)
{
	int mid = left + (right - left) / 2;
	if (array[mid] == key)
		return mid;
	else if (array[mid] < key)
		return Binary1(array, key, mid, right);
	else if (array[mid] > key)
		return Binary1(array, key, left, mid);
	else
		return -1;
}

//非递归版二分法查找
//时间复杂度：O(Log2X)
//空间复杂度：O(1)

int Binary2(int array[], int key, int left, int right)
{
	while (right != left)
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == key)
			return mid;
		else if (array[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
//二分法测试函数
void FunTest1()
{
	int Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = Binary2(Array,5,0,9);
	cout << ret << endl;
}
//递归实现斐波那契数列
//时间复杂度：0（2的N次方）
//空间复杂度：O（N）
long long Fib1(int N)
{
	return N < 2 ? N : (Fib1(N - 1) + Fib1(N - 2));
}
//非递归实现斐波那契数列
//时间复杂度：O(N)
//空间复杂度：O(1)
long long Fib2(int N)
{
	long long first = 0;
	long long second = 1;
	long long third;
	for (int i = 2; i <= N; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}
//数组形式非递归斐波那契数列
//时间复杂度：O(N)
//空间复杂度：O(N)
long long Fib3(int N)
{
	int *arr = new(int[N+1]);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[N];
}
void FunTest2()
{
	long long ret = Fib3(12);
	cout << ret << endl;
}

int main()
{
	FunTest2();
	return 0;
}