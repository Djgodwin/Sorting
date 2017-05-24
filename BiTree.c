//Implementation file for binary tree structure.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BiTree.h"

//Static global node structure for the root.
static treeNode *root;

//Declaration of clearTree function.
static void clearTree(TreeNode *treePtr);

//createTree function calls the clearTree function and initializes the root.
void createTree()
{
	clearTree(root);
	root = NULL;
	return;
}

//The clearTree function takes a node pointer and initializes 
//the left and right children. 
static void clearTree(treeNode *treePtr)
{
	//If the pointer is null. . .
	if(treePtr == NULL)
		//Return from the function.
		return;
	//If the left child is not null. . .
	if(treePtr->left != NULL)
		//Call the ClearTree function with the pointer to the left child. 
		clearTree(treePtr->left);
	//If the right child is not null. . .
	if(treePtr->right != NULL)
		//Call the ClearTree function with the pointer to the right child.
		clearTree(treePtr->right);
	//Free the node pointer.
	free(treePtr);
	//Return from the function.
	return;
}

//The insertNode function inserts a node into the tree.
int insertNode(treeNode *newNode)
{
	//Create two node pointers
	treeNode *temp;
	treeNode *prev;

	//Assign the root node to the temp node
	temp = root;
	//Assign null to the prev node
	prev = NULL;

	//While the temp node is not null. . .
	while(temp != NULL)
	{
		//Assign the temp node to the prev node.
		prev = temp;
		//If the string value in NewNode and the temp node are equal. . .
		if(strcmp(newNode->string, temp->string) == 0)
		{
			//Increment the counter variable in the temp node.
			temp->count++;
			//Free the newNode.
			free(newNode);
			//Return from the function.
			return 1;
		}
		//Otherwise if the string value in newNode is less than the temp node. . . 
		else if(strcmp(newNode->string, temp->string) < 0)
			//Assign the left pointer in temp to the temp node.
			temp = temp->left;
		//Otherwise. . .
		else 
			//Assign the right pointer in temp to the temp node.
			temp = temp->right;
	}
		//If the prev node is null. . .
		if(prev == NULL)
			//Assign the newNode to the root node.
			root = newNode;
		//Otherwise. . .
		else
		{
			//If the string in newNode is less than the prev node. . .
			if(strcmp(newNode->string, prev->string) < 0)
				//Assign the newNode to the left pointer in the prev node.
				prev->left = newNode;
			//Otherwise. . .
			else
				//Assing the newNode to the right pointer in the prev node.
				prev->right = newNode;
		}	
	//Return from the function.
	return 1;
}

//The insert creates a new node and passes it to the insertNode function.
int insert(char *str)
{
	//Creat a node pointer.
	treeNode *newNode;
	
	//Dynamically create a new node.
	newNode = (treeNode *)malloc(sizeof(treeNode));
	//Copy the string passes into the function to the string in the new node.
	strcpy(newNode->string, str);
	//Initialize the counter in the new node to 1.
	newNode->count = 1;
	//Initialize the left and right pointers in the new node to null.
	newNode->left = newNode->right = NULL;
	//Return from the function with the insertNode function.
	return(insertNode(newNode));
}

//The writeTree function traverses the tree and writes
//the values in each node to a file.
void writeTree(treeNode *treePtr, FILE *outFile)
{
	//If the node pointer is not null. . .
	if(treePtr != NULL)
	{
		//Call the writeTree function with the left pointer and the output file.
		writeTree(treePtr->left, outFile);
		//If the first value in the node's string is not a null. . .
		if(treePtr->string[0] != 0)
			//Write the string and count to a file.
			fprintf(outFile, "%-17s %d\n", treePtr->string, treePtr->count);
		//Call the writeTree function with the right pointer and the output file.
		writeTree(treePtr->right, outFile);
	}
}

//The writeToFile function calls the writeTree function with an output file.
void writeToFile(FILE *outFile)
{
	//Call the writeTree function with the root and the output file.
	writeTree(root, outFile);
}
