//Created by Damon Godwin
//Class implementation for a dynamica stack that stores characters
#include <iostream>
#include "DynamicStack.h"
using namespace std;

//This function deletes every node in the list
DynamicStack::~DynamicStack()
{
	StackNode* nodePtr;
	StackNode* nextNode;

	//Position nodePtr at the top of the stack
	nodePtr = top;

	//Traverse the list deleting each node
	while(nodePtr != 0)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//This function inserts the argument onto the stack
void DynamicStack::push(char deliminator)
{
	StackNode* newNode;

	//Allocate a new node
	newNode = new StackNode;
	//If the new node returns a null value, output an error message
	if(newNode == 0)
	{
		cout << "Error allocation memory!" << endl;
		return;
	}
	//Store the character in the new node
	newNode->character = deliminator;

	//If there are no new nodes in the list
	//make newNode the fisrt node
	if(isEmpty())
	{
		top = newNode;
		newNode->next = 0;
	}
	//Otherwise, insert newNode before top
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

//This function removes the character at the top of the stack
//and copies it into the variable passed as an argument
void DynamicStack::pop(char &deliminator)
{
	StackNode* temp;

	//If the stack is empty return an error message
	if(isEmpty())
	{
		cout << "The stack is empty." << endl;
	}
	//Store the character in the top node in the variable passed
	//and assign the previous character in the stack to a temporary
	//node, delete the top node and then store the character in the
	//temporary node in the top node
	else
	{
		deliminator = top->character;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//This function returns true if the stack is empty, or false otherwise
bool DynamicStack::isEmpty()
{
	bool status;

	if(!top)
		status = true;
	else
		status = false;

	return status;
}
