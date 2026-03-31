#pragma once
class Shape {
public:
	virtual void draw();
	virtual ~Shape();
};
class Circle :public Shape {
private:
	float radius;
public:
	void setRadius(float radius);
	void draw();
	~Circle();
};
class Square :public Shape {
private:
	float side;
public:
	void setSide(float side);
	void draw();
	~Square();
};