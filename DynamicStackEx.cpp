//Created by Damon Godwin
//This program reads a file for delimiters and using a dynamic stack class
//object tests the stack for mismatched delimiters
#include <iostream>
#include <fstream>
#include <string>
#include "DynamicStack.h"
using namespace std;

int main()
{
	DynamicStack delimStack;
	string filename;
	char delim;
	char testDelim;
	bool isMatch = false;
	int lineCount = 1;
	int charCount = 0;
	ifstream delimFile;

	//Get the file name for the user and open the file
	cout << "Enter the name of the file you want to test: " << endl;
	getline(cin, filename);
	delimFile.open(filename.c_str());

	//If the file doesn't open output an error message and terminate the program
	if(!delimFile)
	{
		cout << "Error opening file. Terminating program" << endl;
		return 1;
	}

	//While the file is being read
	while(delimFile)
	{
		//Get a character from the file
		delimFile.get(delim);
		//If the character is not a new line increment the character count
		if(delim != '\n')
			charCount++;

		//Determine if the character is a delimiter
		switch(delim)
		{
			//If the character is an opening delimiter push it onto the stack
			case '{':
			case '[':
			case '(':
				delimStack.push(delim);
				break;
			//If the character is a closing delimiter pop a character from
			//the stack. If the delimiters match continue, otherwise output
			//an error, close the file, and terminate the program.
			case '}':
				do
				{
					delimStack.pop(testDelim);
					if(testDelim == '{')
						isMatch = true;
					else 
					{
						cout << "Mismatched delimiter at line " << lineCount;
						cout << " character number " << charCount << endl;
						delimFile.close();
						return 0;
					}
				}while(isMatch == false);
				break;
			case ']':
				do	
				{
					delimStack.pop(testDelim);
					if(testDelim == '[')
						isMatch = true;
					else
					{
						cout << "Mismatched delimiter at line " << lineCount;
						cout << " character number " << charCount << endl;
						delimFile.close();
						return 0;
					}
				}while(isMatch == false);
				break;
			case ')':
				do
				{
					delimStack.pop(testDelim);
					if(testDelim == '(')
						isMatch = true;	
					else
					{
						cout << "Mismatched delimiter at line " << lineCount;
						cout << " character number " << charCount << endl;
						delimFile.close();
						return 0;
					}
				}while(isMatch == false);
				break;
			//If the character is a new line, increment the new line counter
			case '\n':
				lineCount++;
				break;
		}
	}

	//If the stack is empty, output sucess message
	//otherwise output an error message
	if(delimStack.isEmpty())
		cout << "There are no mismatched delimiters." << endl;
	else
		cout << "There are mismatched delimiters." << endl;

	//Close the file
	delimFile.close();

	//End the program
	return 0;
}
