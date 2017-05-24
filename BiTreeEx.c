//This program accepts command line arguments; the first being for input
//and the second for output.  The program then takes text from the input
//file, stores it in a binary tree and outputs it to the second file.
//Created by Damon Godwin.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BiTree.h"

int main(int argc, char *argv[])
{
	//Character array for storing file contents.
	char fileStr[20];
	//Initialize the entire array to a null value.
	memset(fileStr, '\0', 20);
	//String subscript variable.
	int i = 0;

	//Call function to create binary tree.
	CreateTree();
	//Open the input file based on command line argument.
	FILE *inFile = fopen(argv[1], "r");

	//If the input file is null. . .
	if(inFile == NULL)
	{
		//Print an error message.
		printf("The file could not opened.\n");		
	}
	//Otherwise. . .
	else
	{
		//Initialize a variable for getting characters from the file.
		int ch = 0;
		//While the character is not at the end of the file. . .
		while(ch != EOF)
		{
			//Do. . .
			do {
				//Get a character from the file and assign it to the variable.
				ch = fgetc(inFile);
				//If the character is at the end of the file. . . 
				if(ch == EOF)
					//Break the loop.
					break;
				//If the character is an alphabetic character. . .
				if(isalpha(ch))
				{
					//Set the character to lowercase and assign it to the string.
					fileStr[i] = tolower(ch);
					//Increment the string subscript variable.
					i++;
				}
			}while(!isspace(ch));//While the character is not a space.
			//Call the insert function to insert the string into the binary tree.
			insert(fileStr);
			//Reinitialize the string to null for reuse.
			memset(fileStr, '\0', 20);
			//Reset the string subscript variable.
			i = 0;
		}
		//Close the input file.
		fclose(inFile);

		//Open the output file based on the command line argument.
		FILE *outFile = fopen(argv[2], "w");
		//Pass the output file to the writeToFile function to 
		//write the contents of the tree to the file.
		writeToFile(outFile);
		printf("File was written succesfully.\n");
		//Close the output file.
		fclose(outFile);
	}
	//End the program.
	return 0;
}
