#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack() {
	this->top = nullptr;

}
Stack::~Stack() {
	delete this->top;
}
void Stack::push(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}
void Stack::pop() {
	if (isEmpty()) {
		cout << "\nStack is empty"<<endl;
		return;
	}
	Node* temp = top;
	top = top->next;
	delete temp;
}
int Stack::peek() {
	if (isEmpty())return -1;
	return top->data;
}
bool Stack::isEmpty(){
	return top == nullptr;
}
void Stack::print() {
	Node* current = top;
	while (current!=nullptr) {
		cout <<'\t' << current->data << " ";
		current = current->next;

	}
	cout << endl;
}