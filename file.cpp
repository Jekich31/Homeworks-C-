#include "file.h"
#include <iostream>
#include <limits>

int divide(int a, int b) {
	if (b == 0)
		throw DivisionByZeroException();
	return a / b;
}

void readFile(bool exists) {
	if (!exists)
		throw FileNotFoundException();
}

int main() {
	int a, b;

	try {
		std::cout << "Enter two numbers: ";
		std::cin >> a >> b;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw Exception("Error: Invalid input!");
		}

		int result = divide(a, b);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const Exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		readFile(false);
	}
	catch (const FileException& e) {
		std::cout << e.what() << std::endl;
	}
}