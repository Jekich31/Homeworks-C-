#include "rectangle.h"
int Rectangle::count = 0;
Rectangle::Rectangle() : Rectangle::Rectangle(10,10){}

Rectangle::Rectangle(float width, float height) : width(width),height(height){
	count++;
	pointer = new int(10);
}
Rectangle::Rectangle(const Rectangle& source) {
	this->width = source.width;
	this->height = source.height;
	this->pointer = new int(*source.pointer);
}
Rectangle::~Rectangle() {
	count--;
	delete pointer;
}

Rectangle& Rectangle::setW(float width) {
	if (width <= 0)
		cerr << "Width can`t be negative or 0";
	this->width = width;
	return *this;
}
Rectangle& Rectangle::setH(float height) {
	if (width <= 0)
		cerr << "Height can`t be negative or 0";
	this->height = height;
	return *this;
}

float Rectangle::area() {
	return width * height;
}

void Rectangle::print() {
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Area: " << area() << endl;
	cout << "Pointer: " << *pointer << endl;
}