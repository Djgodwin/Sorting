//Created by Damon Godwin
//Specification file for the DynamicStack class
#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

class DynamicStack
{
	private:
		//Structure for stack nodes
		struct StackNode
		{
			char character;//character stored in the node
			StackNode* next;//Pointer to the next node
		};

		StackNode* top;//Pointer to the top of the stack

	public:
		//Constructor
		DynamicStack()
			{top = 0;}

		//Destructor
		~DynamicStack();

	//Stack methods
	void push(char);
	void pop(char &);
	bool isEmpty();
};
#endif
