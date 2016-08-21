// Author: Damon Godwin
// Date: 09_28_2015
// Description: Implementation file for Sort class
#include "Sort.h"
using namespace std;

// bubbleSort method definition
void Sort::bubbleSort(int a[], int n)
{
	bool swapped = true;
	int temp;
	while(swapped)
	{
		swapped = false;
		for(int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swapped = true;
			}
		}                    
	}
}

// cocktailSort method definition
void Sort::cocktailSort(int a[], int n)
{
	bool swapped = true;
	int temp;
	while(swapped)
	{
		swapped = false;
		for(int i = 0; i < n - 1; i++)
		{
			if(a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swapped = true;
			}
		}
		if(!swapped)
			break;
		swapped = false;
		for(int i = n - 1; i > 0; i--)
		{
			if(a[i - 1] > a[i])
			{
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				swapped = true;
			}
		}                    
	}
}

// shellSort1 method definition
void Sort::shellSort1(int a[], int n)
{
	int gap;
	int i;
	int j; 
	int temp;

	for (gap = n/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && a[j] > a[ j + gap]; j -= gap) 
			{
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
			}
		}
	}
}

// shellSort2 method definition
void Sort::shellSort2(int a[], int n)
{
	int gap;
	int i;
	int j; 
	int temp;

	for (gap = n/2; gap > 0; gap -= 5)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && a[j] > a[ j + gap]; j -= gap) 
			{
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
			}
		}
	}
}
