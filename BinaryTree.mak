BinaryTree:BinaryTreeEx.o BinaryTree.o

	g++ -o BinaryTree BinaryTreeEx.o BinaryTree.o



BinaryTreeEx.o:BinaryTreeEx.cpp BinaryTree.h

	g++ -g -c BinaryTreeEx.cpp



BinaryTree.o:BinaryTree.h BinaryTree.cpp

	g++ -g -c BinaryTree.cpp 
