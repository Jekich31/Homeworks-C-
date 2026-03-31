#pragma once
#include <iostream>
using namespace std;
class Rectangle {
private:
	float width;
	float height;
	int* pointer;
public:
	static int count;
	Rectangle();
	Rectangle(float width, float height);
	Rectangle(const Rectangle& source);
	~Rectangle();
	Rectangle& setW(float width);
	Rectangle& setH(float height);
	float area();
	void print();
};