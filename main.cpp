#include <iostream>
#include "Arithmetic.h"
#include "Geometry.h"
using namespace MathPrimitives::Arithmetic;

int main() {
	try {
		Fraction f(3, 5);
		std::cout << "Fraction: ";
		f.print();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Errror: " << e.what() << std::endl;
	}
	MathPrimitives::Geometry::Point2D p2(1.5, 4.0);
	MathPrimitives::Geometry::Point3D p3(10.0, 20.0, 30.0);

	std::cout << "Point 2D: ";
	p2.print();
	std::cout << "\nPoint 3D: ";
	p3.print();
	std::cout << std::endl;

	return 0;
}