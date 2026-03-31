#include "queue.h"
Queue::Queue() {
	this->front = nullptr;
	this->rear = nullptr;

}
Queue::~Queue() {
	delete this->front;
	delete this->rear;
}
void Queue::enqueue(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (rear == nullptr) {
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}
void Queue::dequeue() {
	if (isEmpty()) {
		cout << "\nQueue is empty!";
		return;
	}
	Node* temp = front;
	front = front->next;
	if (front == nullptr) {
		rear = nullptr;
		delete temp;
	}
}
bool Queue::isEmpty() {
	return front == nullptr;
}
void Queue::print() {
	Node* current = front;
	while (current != nullptr) {
		cout << current->data << '\t';
		current = current->next;
	}
	cout << endl;
}