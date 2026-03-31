#include "Shapes.h"
#include <iostream>
#include "exception.h"
using namespace std;
void Shape::draw() {
	cout << "\nImagine shape is drawing...\n";

}
Shape::~Shape() {
	cout << "Shape destructor";
}
void Circle::setRadius(float radius) {
	if (radius <= 0) throw "Radius is 0 or less than 0!\n";
	this->radius = radius;
}
void Circle::draw() {
	cout << "\nImagine circle with radius " << this->radius << " is drawing...\n";
}
Circle::~Circle() {
	cout << "Circle destructor";
}
void Square::setSide(float side) {
	if (side <= 0) throw logic_error("Side can't be 0 or negative");
	this->side = side;
}
void Square::draw() {
	/*throw MyException();*/
	throw MyException::exception();

	cout << "\nImagine square with radius " << this->side << " is drawing...\n";
}
Square::~Square() {
	cout << "Square destructor";
}