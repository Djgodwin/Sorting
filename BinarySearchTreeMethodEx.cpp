//Author: Damon Godwin
//Date: 12/02/15
//Desc: Program implements a binary search tree
//and allows the user to execute various functions.
#include <iostream>
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
	int choice, key, n, k;
	Tree *root = NULL;
	int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
	while(1)
	{
		cout << "Select an option:" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Display In Order" << endl;
		cout << "5. Display Pre Order" << endl;
		cout << "6. Display Post Order" << endl;
		cout << "7. Find Height" << endl;
		cout << "8. Quit" << endl;
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Enter the number of values to be inserted: " << endl;
			cin >> n;
			cout << "Enter value 1:" << endl;
			cin >> k;
			root = insert(root, k);
			cout << "Inserted " << k << endl;
			for(int i = 2; i <= n; i++)
			{
				cout << "Enter value " << i << ":" << endl;
				cin >> k;
				insert(root, k);
				cout << "Inserted " << k << endl;
			}
		}
		else if(choice == 2)
		{
			cout << "Enter a key value:" << endl;
			cin >> key;
			cout << "Search path:" << endl;
			search(root, key);
		}
		else if(choice == 3)
		{
			cout << "Enter a key value:" << endl;
			cin >> key;
			cout << "Deleting " << key << endl;
			deleteNode(root, key);
		}
		else if(choice == 4)
		{
			inOrder(root);
			cout << endl;
		}
		else if(choice == 5)
		{
			preOrder(root);
			cout << endl;
		}
		else if(choice == 6)
		{
			postOrder(root);
			cout << endl;
		}
		else if(choice == 7)
		{
			cout << "The height is " << height(root) << endl;
		}
		else if(choice == 8)
		{
			break;
		}
		else
			cout << "Invalid selection." << endl;
	}
	clear(root);
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
		cout << node->value << endl;
		return node;
	}
	else 
	{
		cout << node->value << endl;
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
		node->count = node->count + 1;
		cout << "Value already in the tree." << endl;
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
