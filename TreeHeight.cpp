//Author: Damon Godwin
//Date: 12/02/15
//Desc: Progrm finds the height for trees of different sizes
//and computes the average height.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Tree node structure
struct Tree
{
	int value;
	int count;
	Tree *left;
	Tree *right;  
	Tree *parent;  
};

//Function declarations
struct Tree *search(struct Tree *, int);
struct Tree *newTreeNode(int);
struct Tree *insert(struct Tree *, int);
int height(struct Tree *);
void deleteNode(struct Tree *, int);
struct Tree *min(struct Tree *);
struct Tree *successor(struct Tree *);
void clear(struct Tree *);
void inOrder(struct Tree *);
void preOrder(struct Tree *);
void postOrder(struct Tree *);

int main()
{
	int key, n, t, x, avgH;
	char choice;
	Tree *root;
	srand(time(NULL));
	
	while(1)
	{
		cout << "Enter the number of nodes: " << endl;
		cin >> n;
		cout << "Enter the number of trees: " << endl;
		cin >> t;
		
		avgH = 0;
		
		for(int i = 0; i < t; i++)
		{
			root = NULL;
			x = rand() % n;
			cout << "Inserting " << x << endl;
			root = insert(root, x);
			for(int j = 0; j < n; j++)
			{
				x = rand() % n;
				cout << "Inserting " << x << endl;
				insert(root, x);	
			}
			cout << "In Order Traversal:" << endl;
			inOrder(root);
			cout << endl;
			cout << "Pre Order Traversal:" << endl;
			preOrder(root);
			cout << endl;
			cout << "Post Order Traversal:" << endl;
			postOrder(root);
			cout << endl;
			avgH = avgH + height(root);
			clear(root);
		}
		cout << "Average height of " << t << " trees with ";
		cout << n << " randomly selected nodes is " << avgH / t << endl; 
		cout << "Continue(y/n)?" << endl;
		cin >> choice;
		if(choice == 'N' || choice == 'n')
		{
			break;	
		}
	}
	return 0;
}

//Function searches a tree structure for a key value
struct Tree *search(struct Tree *node, int key)
{
	if(node == NULL)
	{
		cout << "Key not found." << endl;
		return node;
	}
	if(node->value == key) 
	{
		return node;
	}
	else 
	{
	    if(node->value < key)
			return search(node->right, key);
	    else
			return search(node->left, key);
	}
}

//Creates and initializes a new node
struct Tree *newTreeNode(int key) 
{
	Tree *node = new Tree;
	node->value = key;
	node->count = 1;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

//Inserts a key value into a tree as a new node
struct Tree *insert(struct Tree *node, int key)
{
	static Tree *p;
	Tree *newNode;
	
	//Once an appropriate place is found insert the node.
	if(node == NULL)  
	{
	    newNode = newTreeNode(key);
	    newNode->parent = p;
	    return newNode;
	}
	//If the key is less than the current one, 
	//search the left subtree.
	if(key < node->value) 
	{ 
	    p = node;
	    node->left = insert(node->left, key);
	} 
	//If the key is the same as the current one,
	//increment the nodes count and return.
	else if(key == node->value)
	{
		cout << "Value already in tree. Incrementing count by 1." << endl;
		node->count = node->count + 1;
		return node;
	}
	//If the key is greater than the current one,
	//search the right subtree.
	else 
	{
	    p = node;
	    node->right = insert(node->right, key);
	} 
	return node;
}

//Find the height of a tree
int height(struct Tree *node)
{
	if(node == NULL)
		return -1;
	
	//Find the height of the left and right subtrees	
	int leftHeight = height(node->left);
	int rightHeight = height(node->right);
	
	//Return the height that is greater plus one
	if(rightHeight > leftHeight)
		return rightHeight + 1;
	else
		return leftHeight + 1;	
}

//Function deletes a node with the key value given
void deleteNode(struct Tree *root, int key)
{
	Tree *y, *x;
	//Find the node with key value given
	Tree *z = search(root, key);
	
	if(z->left == NULL || z->right == NULL)
		y = z;
	else
		y = successor(z);
	
	if(y->left != NULL)
		x = y->left;
	else
		x = y->right;
	
	if(x != NULL)
		x->parent = y->parent;
	
	if(y->parent == NULL)
		root = x;
	else if(y == y->parent->left)
		y->parent->left= x;
	else
		y->parent->right = x;
	
	if(y != z)
		z->value = y->value;
}

//Find a minimum value
Tree *min(struct Tree *node)
{
	if(node == NULL) 
		return NULL;
	while(node->left) 
	    node = node->left;
	return node;
}

//Find a successor
Tree *successor(struct Tree *node)
{
	if(node->right != NULL) 
		return min(node->right);

	Tree *y = node->parent;
	while(y != NULL && node == y->right) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

//Clears the tree
void clear(struct Tree *node)
{
	if(node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}

//Traverses the tree in order
void inOrder(struct Tree *node)
{
	if(node == NULL) 
		return;
		
	inOrder(node->left);
	cout << node->value << " ";
	inOrder(node->right);
}

//Traverses the tree post order
void postOrder(struct Tree *node)
{
	if(node == NULL) 
		return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->value << " ";
}

//Traverses the tree pre order
void preOrder(struct Tree *node)
{
	if(node == NULL) 
		return;

	cout << node->value << " ";
	preOrder(node->left);
	preOrder(node->right);
}
