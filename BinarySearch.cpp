#include <iostream>
#include <string>
using namespace std;

const int NUM_PRODS = 9;
const int MIN_PRODNUM = 914;
const int MAX_PRODNUM = 922;

int getProdNum();
int binarySearch(int [], int, int);
void displayProd(string [], string [], double [], int);

int main()
{
	int id[NUM_PRODS] = {914, 915, 916, 917, 918, 918, 920, 921, 922};
	string title[NUM_PRODS] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
	string desc[NUM_PRODS] = {"Book", "Audio", "DVD", "Book", "Audio", "DVD",
														"Book", "Book", "Audio"};
	double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95,
															14.95, 14.95, 16.95};

	int userNum;
	int index;
	char userAgain;

	do
	{
		userNum = getProdNum();

  		index =	binarySearch(id, NUM_PRODS, userNum);
		
		if (index < 0)
			cout << "No product exists with that number" << endl;
		else
			displayProd(title, desc, prices, index);

		cout << "Would you like to look up another product? (Y/N) " << endl;
		cin >> userAgain;
	} while (userAgain == 'Y');

	return 0;
}

int getProdNum()
{
	int num;
	do
	{
		cout << "Please enter a product number: " << endl;
		cin >> num;
  	}	while (num < MIN_PRODNUM || num > MAX_PRODNUM);
}

int binarySearch(int arr[], int size, int searchVal)
{
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		
		if (arr[middle] == searchVal)
		{
			found = true;
			position = middle;
		}
		else if (arr[middle] > searchVal)
			last = middle -1;
		else
			first = middle +1;
	}
		return position;
}

void displayProd(string t[], string d[], double p[], int index)
{
	cout << "Title: " << t[index] << endl;
	cout << "Description: " << d[index] << endl;
	cout << "Price: $" << p[index] << endl;
}
