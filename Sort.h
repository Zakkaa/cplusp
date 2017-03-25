#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
//1.插入排序——升序
void InsertSort(int *a, int n)
{
	assert(a);
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

//希尔排序

void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int tmp = a[i];
			int end = i - gap;
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int* a,int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		int begin = i + 1;
		int minIndex = i;
		while (begin < n)
		{
			if (a[begin] < a[minIndex])
				minIndex = begin;
			++begin;
		}
		swap(a[i], a[minIndex]);
	}
}

//优化版本选择排序
void SelectSort1(int* a, int n)
{
	assert(a);
	int left = 0; int right = n-1;
	while (right >left)
	{
		int minIndex = left;
		int maxIndex = right;
		for (int i = left; i < right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i]>a[maxIndex])
				maxIndex = i;
			swap(a[left], a[minIndex]);
			if (left == maxIndex)
				maxIndex = minIndex;
			swap(a[right], a[maxIndex]);
		}
		left++;
		right--;
	}
}

//堆排序
void _Adjustdown(int* a, int n, int  root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (a[child]<a[child + 1] && (child + 1<n))
			++child;
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		_Adjustdown(a, n, i);
	}
	size_t end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);
		_Adjustdown(a, end, 0);
		--end;
	}
}

//快排

int PartSort1(int *a, int left, int right)//左右指针法
{
	int key = right;
	while (left < right)
	{
		while (left < right&&a[left] <= a[key])//为了防止有数据重复的情况导致排序错误，加=号
			++left;
		while (left < right&&a[right] >= a[key])
			--right;
		if (left < right)
			swap(a[left], a[right]);
	}
	return left;
}

int PartSort2(int *a, int left, int right)//挖坑法
{
	int key = a[right];
	while (right > left)
	{
		while (left < right&&a[left] <= key)
			++left;
		a[right] = a[left];
		while (left<right&&a[right]>=key)
			--right;
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}


int PartSort3(int *a, int left, int right)//左右指针法（应对链表类right无法--的情况）
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur <= right)
	{
		if (a[cur] < key&&(++prev) != cur)
			swap(a[cur], a[prev]);
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}
void QuickSort(int *a, int left,int right)
{
	if (left >= right)
		return;
	if (left < right)
	{
		//if (right - left < 10)
			//InsertSort(a, right - left + 1);//当数据小于10时，使用插入排序，快排在大数据时效率更高
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);
		QuickSort(a, div + 1, right);
		QuickSort(a, left, div - 1);
	}
}

int GetMidCount(int *a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])     //left<mid<right
			return mid;
		else if (a[left] < a[right])//left<right<mid
			return right;
		else                        //right<left<mid   
			return left;
	}
	else
	{
		if (a[mid]>a[right])//right<mid<left
			return mid;
		else if (a[left] > a[right])//mid<right<left
			return right;
		else                        //mid<left<right
			return left;
	}
}

