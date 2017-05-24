//Author: Damon Godwin
//Date: 10/26/15
/*Desc: The program sorts arrays using a merge sort
algorithm and calculates average times of different
sizes of the array.*/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//Function delcarations
void mergeSort(int *, int, int);
void Merge(int *, int, int, int);
void appendNM(int *, int *, int *, int, int);
void mergeNM(int *, int *, int *, int, int); 

int main()
{
	//Variable declarations
	int *arr1;
	int *arr2;
	int *arr3;
	int n;
	int m;
	int x;
	int choice;
	clock_t beg;
	clock_t end;
	double avgT;

	//Seed the random number generator
	srand(time(NULL));
	while(1)
	{
		cout << "Select an option:" << endl;
		cout << "1. Test" << endl;
		cout << "2. Sort & Merge" << endl;
		cout << "3. Append & Resort" << endl;
		cout << "4. Quit" << endl;
		cin >> choice;
	
		if(choice == 4)
		{
			break;
		}
		cout << "Enter a size of n:" << endl;
		cin >> n;
		cout << "Enter a size of m:" << endl;
		cin >> m;
	
		arr1 = new int [n];
		arr2 = new int [m];
		arr3 = new int [n + m];
		avgT = 0;
		
		if(choice == 1)
		{
			for(int j = 0; j < n; j++)
			{
				x = rand() % n;
				arr1[j] = x;
			}
			cout << "Unsorted array of size n:" << endl;
			int count = 0;
			while(count < n)
			{
				for(int j = 0; j < 10; j++)
				{
					if(arr1[count] < 10)
					{
						cout << " " << arr1[count] << " ";
					}
					else
					{
						cout << arr1[count] << " ";
					}	
				}
				cout << endl;
				count++;
			}
			for(int j = 0; j < m; j++)
			{
				x = rand() % m;
				arr2[j] = x;	
			}
	
			count = 0;
			cout << "Unsorted array of size m:" << endl;
			while(count < m)
			{
				for(int j = 0; j < 10; j++)
				{
					if(arr2[count] < 10)
					{
						cout << arr2[count] << " ";
					}
					else
					{
						cout << arr2[count] << " ";
					}	
				}
				cout << endl;
				count++;
			}
			count = 0;
			mergeSort(arr1, 0, n - 1);
			cout << "Sorted array of size n:" << endl;
			while(count < n)
			{
				for(int j = 0; j < 10; j++)
				{
				if(arr1[count] < 10)
					{
						cout << " " << arr1[count] << " ";
					}
					else
					{
						cout << arr1[count] << " ";
					}	
				}
				cout << endl;
				count++;
			}
			mergeSort(arr2, 0, m - 1);
			mergeNM(arr1, arr2, arr3, n, m);
			count = 0;
			cout << "Sorted arrays of size n and m merged:" << endl;
			while(count < n + m)
			{
				for(int j = 0; j < 10; j++)
				{
					if(arr3[count] < 10)
					{
						cout << " " << arr3[count] << " ";
					}
					else
					{
						cout << arr3[count] << " ";
					}	
				}
				cout << endl;
				count++;
			}
			delete arr1;
			delete arr2;
			delete arr3;
		}
		
		else
		{
			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < n; j++)
				{
					x = rand() % n + 1;
					arr1[j] = x;
				}
					
				for(int k = 0; k < m; k++)
				{
					x = rand() % m + 1;
					arr2[k] = x;
				}
		
				//An array of size n is sorted
				beg = clock();
				mergeSort(arr1, 0, n - 1);
				end = clock();
				avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
					
				/*An array of size m is sorted and 
				merged with an array of size n*/
				if(choice == 1)
				{
					beg = clock();
					mergeSort(arr2, 0, m - 1);
					mergeNM(arr1, arr2, arr3, n, m);
					end = clock();
					avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
				}	
		
				/*An array of size m is appended to a sorted 
				array of size n and then resorted*/
				else if(choice == 2)
				{
					beg = clock();
					appendNM(arr1, arr2, arr3, n, m);
					mergeSort(arr3, 0, n + m - 1);
					end = clock();
					avgT = avgT + (double(end - beg) / CLOCKS_PER_SEC) * 1000000;
				}
			}
			delete arr1;
			delete arr2;
			delete arr3;
			
			cout << "Average time: " << avgT / 10 << " microseconds";
		}
	}
	return 0;
}

void mergeNM(int *arr1, int *arr2, int *arr3, int n, int m)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < n && j < m)
	{
		if(arr1[i] <= arr2[j])
		{
			arr3[k] = arr1[i];
			i++;
		}
		else
		{
			arr3[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
 
    while (j < m)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

//Function appends an array of size m to an arry of size n
void appendNM(int *arr1, int *arr2, int *arr3, int n, int m)
{
	int j = 0;
	for(int i = 0; i < n; i++)
	{	
		arr3[i] = arr1[i];
	}
	for(int i = n; i < n + m; i++)
	{
		arr3[i] = arr2[j];
		j++;
	}
}
//Function merges two halves of an array 
void Merge(int *arr, int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;
 
    //Temporary arrays
    int L[n1];
	int R[n2];
 
    //Copy data to temporary arrays
    for(i = 0; i < n1; i++)
	{
        L[i] = arr[p + i];
	}
    for(j = 0; j < n2; j++)
	{
        R[j] = arr[q + 1 + j];
	}
 
    /*Merge the temporary arrays with the original
	sorted order*/
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /*Copy the remaining elements of 
	the arrays to the original array*/
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
//Implementation of merge sort algorithm
void mergeSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}
