#include<iostream>
using namespace std;


//�ݹ����ַ�����
//ʱ�临�Ӷȣ�O(Log2X)
//�ռ临�Ӷȣ�0(Log2X)
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

//�ǵݹ����ַ�����
//ʱ�临�Ӷȣ�O(Log2X)
//�ռ临�Ӷȣ�O(1)

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
//���ַ����Ժ���
void FunTest1()
{
	int Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = Binary2(Array,5,0,9);
	cout << ret << endl;
}
//�ݹ�ʵ��쳲���������
//ʱ�临�Ӷȣ�0��2��N�η���
//�ռ临�Ӷȣ�O��N��
long long Fib1(int N)
{
	return N < 2 ? N : (Fib1(N - 1) + Fib1(N - 2));
}
//�ǵݹ�ʵ��쳲���������
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(1)
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
//������ʽ�ǵݹ�쳲���������
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(N)
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