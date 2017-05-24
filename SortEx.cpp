// Author: Damon Godwin
// Date: 09_28_2015
/* Description: Program uses different sorting algorithms to sort
arrays of different sizes and outputs average time for a given size */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sort.h"

using namespace std;

int main()
{
	// Variable declarations
	Sort sort;
	int choice;
	int arrLength[] = {500, 1000, 2500, 5000};
	int length;
	double avgT;
	int *arr;
	int x;
	clock_t start;
	clock_t end;

	// Seed random number generator
	srand(time(NULL));

	//Loop until user quits
	while(1)
	{
		// Display menu
		cout << "1. Bubble Sort" << endl;
		cout << "2. Cocktail Sort" << endl;
		cout << "3. Shell Sort #1" << endl;
		cout << "4. Shell Sort #2" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter the corresponding number to calculate" << endl;
		cout << "average time for the given algorithm: " << endl;
		cin >> choice;

		if(choice == 1)
		{
			cout << "Bubble Sort:" << endl;
		}
		else if(choice == 2)
		{
			cout << "Cocktail Sort:" << endl;
		}
		else if(choice == 3)
		{
			cout << "Shell Sort #1:" << endl;
		}
		else if(choice == 4)
		{
			cout << "Shell Sort #2:" << endl;
		}
		else if(choice == 5)
		{
			break;
		}
		// Create 10 arrays of 4 different sizes
		for(int i = 0; i < 4; i++)
		{
			avgT = 0;
			length = arrLength[i];
			for(int j = 0; j < 10; j++)
			{
				arr = new int[length];
				for(int k = 0; k < length; k++)
				{
					x = rand() % length;
					arr[k] = x;
				}
				// Based on user input, use the corresponding algorithm
				if(choice == 1)
				{
					// Get the start time
					start = clock();
					// Call sorting algorithm
					sort.bubbleSort(arr, length);
					// Get the end time
					end = clock();
					// Calculate time the function took in microseconds
					avgT = avgT + (double(end - start) / CLOCKS_PER_SEC) * 1000000;
				}
				else if(choice == 2)
				{
					start = clock();
					sort.cocktailSort(arr, length);
					end = clock();
					avgT = avgT + (double(end - start) / CLOCKS_PER_SEC) * 1000000;
				}
				else if(choice == 3)
				{
					start = clock();
					sort.shellSort1(arr, length);
					end = clock();
					avgT = avgT + (double(end - start) / CLOCKS_PER_SEC) * 1000000;
				}
				else if(choice == 4)
				{
					start = clock();
					sort.shellSort2(arr, length);
					end = clock();
					avgT = avgT + (double(end - start) / CLOCKS_PER_SEC) * 1000000;
				}
				// Clear allocated memory
				delete arr;
			}
			// Display average time for a group
			cout << "Average time for arrays of size " << length;
			cout << ": " << avgT / 10 << " microseconds" << endl;
		}
	}
	return 0;
}
