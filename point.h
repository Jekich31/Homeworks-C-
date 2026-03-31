#pragma once
#include <iostream>
class Point {
	int x, y;
public:
	Point();
	Point(int x, int y);
	explicit Point(int x);
	int getX() const;
	int getY() const;
	void move(int dx, int dy);


	Point operator+(const Point& other);
	Point operator*(const Point& other);
	bool operator>(const Point& other);
	Point& operator++();
	Point& operator++(int);
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
};