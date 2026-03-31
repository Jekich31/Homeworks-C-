#pragma once
#include "node.h"
#include <iostream>
using namespace std;
class Queue {
private:
	Node* front;//початок
	Node* rear;//кінець
public:
	Queue();
	~Queue();
	void enqueue(int value);
	void dequeue();
	bool isEmpty();
	void print();
};