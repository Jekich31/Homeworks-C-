#include "list.h"
#include <iostream>
using namespace std;
List::List() {
	this->head = nullptr;
}
List::~List() {
	delete this->head;
}
void List::addFront(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;

}
void List::addBack(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}
void List::deleteValue(int value) {
	if (head == nullptr) {
		cout << "\nList is empty!";
		return;
	}
	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		if (current->next->data==value) {
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
			return;
		}
		current = current->next;
	}
}
void List::print() {
	Node* current = head;
	while (current != nullptr) {
		cout <<'\t' << current->data << "\n";
		current = current->next;
	}
	cout << endl;
}
bool List::find(int value) {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value)
			return true;
		current = current->next;
	}
	return false;
}