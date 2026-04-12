#pragma once
#include <iostream>

namespace MathPrimitives::Geometry {
	class Point2D {
	protected:
		double x, y;

	public:
		Point2D(double x, double y) : x(x), y(y) {}

		virtual void print() const {
			std::cout << "Point2D(" << x << ", " << y << ")";
		}
	};

	class Point3D : public Point2D {
	private:
		double z;

	public:
		Point3D(double x, double y, double z) : Point2D(x, y), z(z) {}

		void print() const override {
			std::cout << "Point3D(" << x << ", " << y << ", " << z << ")";
		}
	};
}