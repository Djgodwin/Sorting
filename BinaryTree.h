//Specification file for BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>
#include <fstream>

class BinaryTree
{
	private:
		struct TreeNode
		{
			std::string subStr;//String value in the node
			int count;//Counter value in the node
			TreeNode* left;//Pointer to the left child
			TreeNode* right;//Pointer to the right child
		};

		TreeNode* root;//Pointer to the root node

		//Private member functions
		void insert(TreeNode*&, TreeNode*&);
		void displayInOrder(TreeNode*) const;
		void destroySubTree(TreeNode*);

	public:
		//Constructor
		BinaryTree()
			{root = 0;}
		
		//Destructor
		~BinaryTree()
			{destroySubTree(root);}

		//Binary tree operations
		void insertNode(std::string);
		void writeInOrder(TreeNode*, std::ofstream&) const;
		TreeNode* getRoot() const
			{return root;}


};
#endif
