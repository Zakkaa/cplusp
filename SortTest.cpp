#include"Sort.h"

void PintArray(int *a,int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void TestInsertSort(int *a,int n)
{
	InsertSort(a, n);
	PintArray(a, n);
}
void TestShellSort(int *a, int n)
{
	ShellSort(a, n);
	PintArray(a, n);
}
void TestSelectSort(int *a, int n)
{
	SelectSort(a, n);
	PintArray(a, n);
}
void TestSelectSort1(int* a, int n)
{
	SelectSort1(a, n);
	PintArray(a, n);
}
void TestHeapSort(int *a, int n)
{
	HeapSort(a, n);
	PintArray(a, n);
}
void TestQuickSort(int* a, int n)
{
	QuickSort(a, 0, n-1);
	PintArray(a, n);
}
int main()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	//TestInsertSort(a,n);
	//TestShellSort(a,n);
	//TestSelectSort(a, n);
	//TestSelectSort1(a, n);
	//TestHeapSort(a, n);
	TestQuickSort(a, n);
	return 0;
}


 