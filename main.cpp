#include "rectangle.h"
#include "point.h"
#include "box.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
#include "inheritance.h"
#include "Shapes.h"
#include "exception.h"
void testStaticArr();
void TestStack();
//void TestPoint();
void TestBox();
void TestQueue();
void TestList();
void TestInheritance();
void secretFunc(Parent* parent);
void TestShapes();
void TestExpections();
int main() {
	/*TestBox();*/
	/*TestStack();*/
	/*TestQueue();*/
	/*TestList();*/
	/*TestInheritance();*/
	/*TestShapes();*/
	TestExpections();
}
void testStaticArr() {
	Rectangle rectangles[5] = {
		{15,15},
		{},
		{},
		{},
		{},
	};

	for (int i = 0; i < 5; i++) {
		rectangles[i].print();
		cout << endl;
	}
} 
void TestBox() {
	Box<int> box1(123);
	Box<string> box2;
	Box<float> box3;
	cout << "Enter box 2 value(string): ";
	cin >> box2;
	cout << "\nBox 2 value is: " << box2.get();

}
void TestStack() {
	Stack stack;
	for (int i = 0; i < 13; i++) {
		stack.push(i);
	}
	int peek = stack.peek();
	if (stack.peek() != -1) cout << "Peek is: " << peek << endl;
	stack.pop();
	cout << "Stack is: \n" << endl;
	stack.print();
}
void TestQueue() {
	Queue queue;
	queue.enqueue(11);
	queue.enqueue(21);
	queue.enqueue(31);
	cout << "Queue before:" << endl;
	queue.print();
	queue.dequeue();
	cout << "Queue after:" << endl;
	queue.print();
}
void TestList() {
	List list;
	list.addFront(40);
	list.addBack(122);
	list.addFront(50);
	cout << "\nList is: \n";
	list.print();
	cout << "\nlist.find(22): " << list.find(22);
	cout << "\nlist.find(62): " << list.find(62);
	list.deleteValue(40);
	cout << "\nList after is: \n";
	list.print();
}
void TestInheritance() {
	//Brother brother;
	//cout << "brother name is " << brother.getName()<<endl;
	Parent parent;
	secretFunc(&parent);
	Child child("Andriy",15,"male","blue","red","watching anime");
	secretFunc(&child);

}
void secretFunc(Parent* parent) {
	parent->tellSecret();
}
//void TestShapes() {
//	
//	Shape* shape = new Shape();
//	Shape* circle = new Circle();
//	Shape* square = new Square();
//
//	shape->draw();
//	circle->draw();
//	square->draw();
//
//}
//void TestShapes() {
//	Shape* shape = new Square();
//	delete shape;
//}
void TestShapes() {
	float radius;
	Circle* circle = new Circle();
	cout << "Enter radius -> ";
	cin >> radius;
	try{
		circle->setRadius(radius);
		circle->draw();
	}
	catch(const char* exception){
		cout << "Exception thrown: " << exception<<endl;
	}
	catch (...) {
		cout << "Something went wrong...";
	}


}

void TestExpections(){
	//long long size = 9980890648996048563;

	///*float side;
	//Square* square=new Square();
	//cout << "Enter side -> ";
	//cin >> side;
	//try {
	//	square->draw();
	//}
	//catch(MyException& ex){
	//	cout << "Exception thrown: " << ex.what() << endl;*/
	//try{
	//	int* arr = new int[size];
	//}
	//catch(bad_alloc& ex){
	//	cout << "Bad memory allocation: "<<ex.what()<<endl;
	//}
	Square square;
	try {
		square.draw();
	}
	catch (MyException::exception ex) {
		cout << "Exception thrown: " << ex.what() << endl;
	}
	catch (...) {
		cout << "Something went wrong!" <<endl;
	}
}