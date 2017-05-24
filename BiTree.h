//Header file for binary tree structure.
#ifndef BITREE_H
#define BITREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition of node structure. . .
typedef struct treeNodeType {
	//String variable
	char string[20];
	//Counter variable
	int count;
	//Node pointer for left children.
	struct treeNodeType *left;
	//Node pointer for right children.
	struct treeNodeType *right;
}treeNode;

//Function prototypes.
void createTree();
int insertNode(treeNode *);
int insert(char *);
void writeTree(treeNode *, FILE *);
void writeToFile(FILE *);

#endif
