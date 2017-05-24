//Implementation file for the BinaryTree class
#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

//This function accepts a TreeNode pointer and a pointer to a node
//The function inserts the node into the tree pointed to by the
//TreeNode pointer.
void BinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	//If the nodePtr contains a null
	//insert the node.
	if(nodePtr == 0)
		nodePtr = newNode;
	//If the string in the newNode is the same as the one in nodePtr
	//increment the counter in nodePtr delete newNode and return.
	else if(newNode->subStr == nodePtr->subStr)
	{
		nodePtr->count++;
		delete newNode;
		return;
	}
	//If the string in the newNode is less than the one in nodePtr
	//search the left branch recursively.
	else if(newNode->subStr < nodePtr->subStr)
		insert(nodePtr->left, newNode);
	//Otherwise search the right branch recursively.
	else
		insert(nodePtr->right, newNode);
}

//This function creates a new node to hold the string
//and passes it to the insert function.
void BinaryTree::insertNode(string sStr)
{
	//Pointer to a new node.
	TreeNode* newNode;
	
	//Attempt to create a new node.
	newNode = new TreeNode;
	//If newNode contains a null output an error message and return.
	if(newNode == 0)
	{
		cout << "Error allocating memory.";
		return;
	}
	//Assign the string passed to the function to the string value
	//in newNode.
	newNode->subStr = sStr;
	//Increment the counter variable in newNode.
	newNode->count = 1;
	//Initialize the newNode's left and right pointer variables to null.
	newNode->left = newNode->right = 0;

	//Insert the node
	insert(root, newNode);
}

//This function is called by the destructor, which
//deletes all nodes in the tree.
void BinaryTree::destroySubTree(TreeNode* nodePtr)
{
	//If nodePtr contains a value
	if(nodePtr)
	{
		//If the pointer in left contains a value
		if(nodePtr->left)
			//Call the function recursively
			destroySubTree(nodePtr->left);
		//If the pointer in right contains a value
		if(nodePtr->right)
			//Call the function recursively
			destroySubTree(nodePtr->right);
		//Delete nodePtr		
		delete nodePtr;
	}
}

//This function traverses the tree inorder and writes the values
//contained in nodePtr to a file.
void BinaryTree::writeInOrder(TreeNode* nodePtr, ofstream& countFile) const
{
	//If nodePtr contains a value
	if(nodePtr)
	{
		//Call the function recursively
		writeInOrder(nodePtr->left, countFile);
			//If the string value in nodePtr is not empty
			if(!nodePtr->subStr.empty())
			//Write the string and counter values to the file		
			countFile << nodePtr->subStr << ": " << nodePtr->count << endl;
		//Call the function recursively		
		writeInOrder(nodePtr->right, countFile);
	}
}
