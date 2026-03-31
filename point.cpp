#include "point.h"
Point::Point() :x(0), y(0){}
Point::Point(int x, int y) 
	:x(x), y(y){ }
Point::Point(int x) :x(x),y(0) {}
int Point::getX() const{
	return this->x;
}
int Point::getY() const {
	return this->y;
}
void Point::move(int dx, int dy) {
	this->x += dx;
	this->y += dy;
}
Point Point::operator+(const Point& other) {
	int x = this->x + other.x;
	int y = this->y + other.y;
	return Point(x, y);
}
Point Point::operator*(const Point& other) {
	int x = this->x * other.x;
	int y = this->y*other.y;
	return Point(x, y);
}
bool Point::operator>(const Point& other) {
	if ((this->x > other.x) && (this->y > other.y))
		return true;
	return false;
}
Point& Point::operator++() {
	this->x++;
	this->y++;
	return *this;
	}
Point& Point::operator++(int) {
	this->x++;
	this->y++;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "\nx: " <<point.x<<"\n\ty: "<<point.y<<"\n";
	return os;
}
