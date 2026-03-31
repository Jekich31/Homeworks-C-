#pragma once
#include "node.h"
class List {
private:
	Node* head;
public:
	List();
	~List();
	void addFront(int value);
	void addBack(int value);
	void deleteValue(int value);
	void print();
	bool find(int value);

};