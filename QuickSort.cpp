//Author: Damon Godwin
//Date: 10/26/15
/*Desc: Program implements three different quick sort algrothims
for random arrays of various sizes and calculates the average times.*/
#include<iostream>
#include<ctime>

using namespace std;

//Function declarations
void quickSort(int *, int, int);
int Partition(int *, int, int);
int medOfThreePartition(int *, int, int);
void medOfThreeQuickSort(int *, int, int);
int medOfFivePartition(int *, int, int);
void medOfFiveQuickSort(int *, int, int);

int main()
{
	//Variable declarations
	int *arr;
	int *arr2;
	int *arr3;
	int x;
	int k;
	int n;
	clock_t beg;
	clock_t end;
	double avgT = 0;
	int choice;

	//Seed the random number generator
	srand(time(NULL));

	while(1)
	{
		cout << "Select an option:" << endl;
		cout << "1. Test" << endl;
		cout << "2. Quick Sort" << endl;
		cout << "3. Median of Three Quick Sort" << endl;
		cout << "4. Median of Five Quick Sort" << endl;
		cout << "5. Quit" << endl;
		cin >> choice;
		
		if(choice == 5)
		{
			break;
		}

		cout << "Enter a size of n:" << endl;
		cin >> n;
		
		arr = new int[n];
		avgT = 0;

		if(choice == 1)
		{
			arr2 = new int[n];
			arr3 = new int[n];
	
			for(int i = 0; i < n; i++)
			{
				x = rand() % n + 1;
				arr[i] = x;
				arr2[i] = x;
				arr3[i] = x;
			}
			k = 0;
			cout << "Unsorted array:" << endl;
			while(k < n)
			{
				for(int i = 0; i < 10; i++)
				{
					if(arr[k] < 10)
					{
						cout << " " << arr[k] << " ";
					}
					else
					{
						cout << arr[k] << " ";
					}
					k++;
				}
				cout << endl;
			}
			cout << endl;
			k = 0;
			quickSort(arr, 0, n - 1);
			cout << "Array sorted with quick sort:" << endl;
			while(k < n)
			{
				for(int i = 0; i < 10; i++)
				{
					if(arr[k] < 10)
					{
						cout << " " << arr[k] << " ";
					}
					else
					{
						cout << arr[k] << " ";
					}
				k++;
				}
				cout << endl;
			}
			cout << endl;
			k = 0;
			medOfThreeQuickSort(arr2, 0, n - 1);
			cout << "Array sorted with median of three quick sort:" << endl;
			while(k < n)
			{
				for(int i = 0; i < 10; i++)
				{
					if(arr2[k] < 10)
					{
						cout << " " << arr2[k] << " ";
					}
					else
					{
						cout << arr2[k] << " ";
					}
				k++;
				}
				cout << endl;
			}
			cout << endl;
			k = 0;
			medOfFiveQuickSort(arr3, 0, n - 1);
			cout << "Array sorted using median of five quick sort:" << endl;
			while(k < n)
			{
				for(int i = 0; i < 10; i++)
				{
					if(arr3[k] < 10)
					{
						cout << " " << arr3[k] << " ";
					}
					else
					{
						cout << arr3[k] << " ";
					}
				k++;
				}
				cout << endl;
			}
			cout << endl;
			delete arr2;
			delete arr3;
		}
		else
		{
			for(int j = 0; j < 10; j++)
			{
				for(int i = 0; i < n; i++)
				{
					x = rand() % n + 1;
					arr[i] = x;
				}
				if(choice == 2)
				{
					beg = clock();
					quickSort(arr, 0, n - 1);
					end = clock();
					avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
				}
				else if(choice == 3)
				{
					beg = clock();
					medOfThreeQuickSort(arr, 0, n - 1);
					end = clock();
					avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
				}
				else
				{
					beg = clock();
					medOfFiveQuickSort(arr, 0, n - 1);
					end = clock();
					avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
				}
			}
			cout << "Average time: " << avgT / 10 << " microseconds" << endl;
		}
		delete arr;
	}
	return 0;
}

void quickSort(int *arr, int p, int r)
{
	int q;

	if(p < r)
	{
		q = Partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

void medOfThreeQuickSort(int *arr, int p, int r)
{
	int q;

	if(p < r)
	{
		q = medOfThreePartition(arr, p, r);
		medOfThreeQuickSort(arr, p, q - 1);
		medOfThreeQuickSort(arr, q + 1, r);
	}
}

void medOfFiveQuickSort(int *arr, int p, int r)
{
	int q;

	if(p < r)
	{
		q = medOfFivePartition(arr, p, r);
		medOfFiveQuickSort(arr, p, q - 1);
		medOfFiveQuickSort(arr, q + 1, r);
	}
}

/*Function partitions an array and sorts it
using a pivot value that is the rightmost value
in the array*/
int Partition(int *arr, int p, int r)
{
	int tmp;
	int pivot = arr[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;
	return i + 1;
}

/*Function partitions an array and sorts it
using a pivot value that is selected by finding
the median of three values in the array*/
int medOfThreePartition(int *arr, int p, int r)
{
	int q = (p + r) / 2;
	int tmp;

	if(arr[q] < arr[p])
	{
		tmp = arr[p];
		arr[p] = arr[q];
		arr[q] = tmp;
	}
	if(arr[q] > arr[r])
	{
		tmp = arr[r];
		arr[r] = arr[q];
		arr[q] = tmp;
	}
	if(arr[p] > arr[r])
	{
		tmp = arr[r];
		arr[r] = arr[p];
		arr[p] = tmp;
	}
	
	tmp = arr[q];
	arr[q] = arr[r];
	arr[r] = tmp;
	
	int pivot = arr[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;
	return i + 1;
}

/*Function partitions an array and sorts it using a
pivot value that is selected from the median of five 
random numbers in the array*/
int medOfFivePartition(int *arr, int p, int r)
{
	//Five random subscripts are chosen
	int x1 = rand() % (r - p) + p;
	int x2 = rand() % (r - p) + p;
	int x3 = rand() % (r - p) + p;
	int x4 = rand() % (r - p) + p;
	int x5 = rand() % (r - p) + p;

	int tmp;
	
	//An array is made up of five values randomly chosen
	int arr2[] = {arr[x1], arr[x2], arr[x3], arr[x4], arr[x5]};
	
	//The array of five values is sorted
	quickSort(arr2, 0, 4);
	
	/*Exhange the median value of the five numbers
	with the middle element*/
	if(arr[x1] == arr2[2])
	{
		tmp = arr[x1];
		arr[x1] = arr[r];
		arr[r] = tmp;
	}
	else if(arr[x2] == arr2[2])
	{
		tmp = arr[x2];
		arr[x2] = arr[r];
		arr[r] = tmp;
	}
	else if(arr[x3] == arr2[2])
	{
		tmp = arr[x3];
		arr[x3] = arr[r];
		arr[r] = tmp;
	}
	else if(arr[x4] == arr2[2])
	{
		tmp = arr[x4];
		arr[x4] = arr[r];
		arr[r] = tmp;
	}
	else
	{
		tmp = arr[x5];
		arr[x5] = arr[r];
		arr[r] = tmp;
	}

	int pivot = arr[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;
	return i + 1;
}
