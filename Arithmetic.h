#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

namespace MathPrimitives::Arithmetic {
	class Fraction {
	private:
		int numerator;
		int denominator;

	public:
		Fraction(int num, int den) : numerator(num), denominator(den) {
			if (den == 0) {
				throw std::invalid_argument("Denominator cannot be zero.");
			}
		}

		void print() const {
			std::cout << numerator << "/" << denominator;
		}
	};
}