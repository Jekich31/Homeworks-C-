#pragma once
#include "node.h"
class Stack {
private:
	Node* top;
public:
	Stack();
	~Stack();
	void push(int value);
	void pop();
	int peek();
	bool isEmpty();
	void print();
};