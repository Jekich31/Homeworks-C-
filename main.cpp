#include <iostream>
#include <cmath>

class Equation {
public:
	virtual void solve() = 0;
	virtual ~Equation() {}
};

class LinearEquation : public Equation {
private:
	double a, b;

public:
	LinearEquation(double a, double b) : a(a), b(b) {}

	void solve() override {
		if (a == 0) {
			if (b == 0)
				std::cout << "Безліч розв'язків\n";
			else
				std::cout << "Розв'язків немає\n";
		}
		else {
			std::cout << "x = " << -b / a << "\n";
		}
	}
};

class QuadraticEquation : public Equation {
private:
	double a, b, c;

public:
	QuadraticEquation(double a, double b, double c)
		: a(a), b(b), c(c) {
	}

	void solve() override {
		if (a == 0) {
			std::cout << "Це не квадратне рівняння\n";
			return;
		}

		double D = b * b - 4 * a * c;

		if (D > 0) {
			std::cout << "x1 = " << (-b + sqrt(D)) / (2 * a)
				<< ", x2 = " << (-b - sqrt(D)) / (2 * a) << "\n";
		}
		else if (D == 0) {
			std::cout << "x = " << -b / (2 * a) << "\n";
		}
		else {
			std::cout << "Дійсних коренів немає\n";
		}
	}
};

int main() {
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "uk_UA.UTF-8");

	int choice;
	std::cout << "Оберіть тип рівняння:\n";
	std::cout << "1 - Лінійне (ax + b = 0)\n";
	std::cout << "2 - Квадратне (ax^2 + bx + c = 0)\n";
	std::cout << "Ваш вибір: ";
	std::cin >> choice;

	Equation* eq = nullptr;

	if (choice == 1) {
		double a, b;
		std::cout << "Введіть a і b: ";
		std::cin >> a >> b;
		eq = new LinearEquation(a, b);
	}
	else if (choice == 2) {
		double a, b, c;
		std::cout << "Введіть a, b і c: ";
		std::cin >> a >> b >> c;
		eq = new QuadraticEquation(a, b, c);
	}
	else {
		std::cout << "Невірний вибір\n";
		return 0;
	}

	eq->solve();

	delete eq;
	return 0;
}