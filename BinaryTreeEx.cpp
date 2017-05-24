//Created by Damon Godwin
//This program reads a text file and inserts a substring into
//a binary tree. It then writes the contents of the tree to a
//file using inorder traversal.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "BinaryTree.h"
using namespace std;

int main()
{
	//Variables.
	BinaryTree subStrTree;
	ifstream encodedFile;
	ofstream countFile;
	string filename;
	string encodedStr;
	char ch;
	int maxSubStr2;
	int maxSubStr;

	//Get the filename from the user.
	cout << "Enter the filename: " << endl;
	getline(cin, filename);

	//Attempt to open the file
	encodedFile.open(filename.c_str());

	//If the file doesn't open output an
	//error message and terminate the program.
	if(!encodedFile)
	{
		cout << "Error opening file." << endl;
		return 1;
	}

	//Get the maximum length of substrings to insert into the tree.
	cout << "Enter the maximum length of substrings: " << endl;
	cin >> maxSubStr;

	//Assign the maximum substring value to a second variable.
	maxSubStr2 = maxSubStr;

	//While the file is being read.
	while(encodedFile)
	{
		//Get a character from the file.
		encodedFile.get(ch);

		//If the character is not
		// a space, new line, or null.
		if(ch != ' ')
		{
			if(ch != '\n')
			{
				if(ch != 0)
				{
					//Convert the letter to an uppercase letter.
					ch = toupper(ch);
					//Add the character to encodedStr.
					encodedStr += ch;
				}
			}
		}
	}
	//Close the file.
	encodedFile.close();

	//Increment pos if it less than or equal to the string length.
	for(int pos = 0; pos <= encodedStr.length(); pos++)
	{
		//If the pos is greater than the string lenght minus
		//the maximum substring value.
		if(pos > encodedStr.length() - maxSubStr)
		{
			//Increment the second substring counter if it is
			//less than the second maximum substring value.
			for(int subStr2 = 0; subStr2 < maxSubStr2; subStr2++)
				//Insert a substring at the pos value of the length
				//of the second substring counter.
				subStrTree.insertNode(encodedStr.substr(pos, subStr2));
			maxSubStr2--;//Increment the second maximum substring value.
		}
		//Otherwise, increment the first substring counter if it
		//is less than or equal to the first maximum substring value.
		else
			for(int subStr = 0; subStr <= maxSubStr; subStr++)
				//Insert a substring at the pos value of the length
				//of the first substring counter.
				subStrTree.insertNode(encodedStr.substr(pos, subStr));
	}

	//Open a file to write the tree to.
	countFile.open("counts.txt");
	//Call the write function.
	subStrTree.writeInOrder(subStrTree.getRoot(), countFile);
	//Close the file.
	countFile.close();

	cout << "counts.txt file writen succesfully." << endl;

	//End the program.
	return 0;
}
