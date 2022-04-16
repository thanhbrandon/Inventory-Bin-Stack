#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
#include "InventoryPart.h"
using namespace std;

class DynamicStack
{
private:
	// Structure for the stack node
	struct StackNode
	{
		InventoryPart value = InventoryPart(666,"TEST",666); // Value in the node 
		StackNode* next; // Pointer to the next node
	};

	StackNode* top; // Pointer to the stack top

public:
	// Constructor 
	DynamicStack() 
	{
		top = nullptr ;
	}

	// Destructor 
	~DynamicStack();

	// Stack operations
	void push(InventoryPart);
	void pop(InventoryPart&);
	void peek();
	bool isEmpty();
};

DynamicStack::~DynamicStack()
{
	StackNode* nodePtr, * nextNode;

	// Position nodePtr at the top of the stack
	nodePtr = top;

	// Traverse the list deleting each node
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

// Member function push pushes the arguement into the stack
void DynamicStack::push(InventoryPart item)
{
	StackNode* newNode = nullptr; // Pointer to a new node

	// Allocate a new node and store num there.
	newNode = new StackNode;
	newNode->value = item;

	// If there are no nodes in the list make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

// Member function pop pops the value at the top of the stack off, 
// and copies it into the variable passed as an argument

void DynamicStack::pop(InventoryPart& item)
{
	StackNode* temp = nullptr; // Temporary pointer

	// First make sure the stack isn't empty
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else // pop value off top of stack
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

// Member function is Empty returns true if the stack is empty,
// or false otherwise
bool DynamicStack::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;
	
	return status;
}


void DynamicStack::peek()
{
	cout << "The last item entered info:\n";
	cout << "Serial Numbers : " << top->value.getSerialNum() << "\n";
	cout << "Date of Manufacture : " << top->value.getManufactDate() << "\n";
	cout << "Lot number: " << top->value.getLotNum() << "\n";

}
#endif
#pragma once
