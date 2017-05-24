//Author: Damon Godwin
//Date: 11/02/15
/*Desc: Program implements a bottom-up heapsort
algorithm and calculates average times for sorting
arrays of different sizes*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

//Function declarations
void heapSort(int *, int);
void build_maxHeap(int *, int);
void max_heapify(int *, int, int);

int main()
{
	//Variable declarations
	int *arr;
	int n;
	int x;
	int choice;
	clock_t begCnstr, begSort;
	clock_t endCnstr, endSort;
	double avgT, avgTc;
	
	//Seed random number generator
	srand(time(NULL));
	
	while(1)
	{
		cout << "Select an option:" << endl;
		cout << "1. Test" << endl;
		cout << "2. Heap Sort" << endl;
		cout << "3. Quit" << endl;
		
		cin >> choice;
		
		if(choice == 3)
		{
			break;
		}
		else
		{
			cout << "Enter a size of n:" << endl;
			cin >> n;
			
			arr = new int[n];
			avgT = 0;
			avgTc = 0;
			if(choice == 1)
			{
				for(int j = 0; j < n; j++)
				{
					x = rand() % n;
					arr[j] = x;
				}
				cout << "Unsorted array:" << endl;
				int k = 0;
				while(k < n)
				{
					for(int i = 0; i < 25; i++)
					{
						if(arr[k] < 10)
						{
							cout << " " << arr[k] << " ";
						}
						else
						{
							cout << arr[k] << " ";
						}
					}
					cout << endl;
					k++;
				}
				k = 0;
				build_maxHeap(arr, n - 1);
				cout << "Heap representation of an array:" << endl;
				while(k < n)
				{
					for(int i = 0; i < 25; i++)
					{
						if(arr[k] < 10)
						{
							cout << " " << arr[k] << " ";
						}
						else
						{
							cout << arr[k] << " ";
						}
					}
					cout << endl;
					k++;
				}
				k = 0;
				heapSort(arr, n - 1);
				cout << "Sorted array:" << endl;
				while(k < n)
				{
					for(int i = 0; i < 25; i++)
					{
						if(arr[k] < 10)
						{
							cout << " " << arr[k] << " ";
						}
						else
						{
							cout << arr[k] << " ";
						}
					}
					cout << endl;
					k++;
				}
			}
			else
			{
				for(int i = 0; i < 100; i++)
				{
					for(int j = 0; j < n; j++)
					{
						x = rand() % n;
						arr[j] = x;
					}
					//Construct a heap representation of an array
					begCnstr = clock();
					build_maxHeap(arr, n - 1);
					endCnstr = clock();
					avgTc = avgTc + (double(endCnstr - begCnstr) / CLOCKS_PER_SEC) * 1000000;
					//Sort the array
					begSort = clock();
					heapSort(arr, n - 1);
					endSort = clock();
					avgT = avgT + (double(endSort - begSort) / CLOCKS_PER_SEC) * 1000000;
				}
				cout << "Average time of construction: " << avgTc / 100 << " microseconds" << endl;
				cout << "Average time of sorting: " << avgT / 100 << " microseconds" << endl;
				cout << "Total average time: " << (avgTc + avgT) / 100 << " microseconds" << endl;
			}
		}
		delete arr;
	}
	return 0;			
}

//Heap Sort algorithm implementation
void heapSort(int *arr, int n)
{
	int tmp;
	int heapSize = n;
	//Sort elements as a heap structure
	for(int i = n; i >= 1; i--)
	{
		tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		heapSize = heapSize - 1;
		max_heapify(arr, 0, heapSize);
	}
}

//Function builds a max heap representation of an array
void build_maxHeap(int *arr, int n)
{
	int heapSize = n;
	for(int i = (n - 1) / 2; i >= 0; i--)
	{
		max_heapify(arr, i, heapSize);
	}
}

/*Function ensures the parental dominance requirement
is satisfied for the heap representation*/
void max_heapify(int *arr, int i, int heapSize)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	int tmp;
	if(l <= heapSize && arr[l] > arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r <= heapSize && arr[r] > arr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		max_heapify(arr, largest, heapSize);	
	}
}
