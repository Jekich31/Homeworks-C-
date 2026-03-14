//домашнє завдання за 10.03
#include "main.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix<int> A(3, 3);
    Matrix<int> B(3, 3);

    A.randomFill();
    B.randomFill();

    cout << "A:\n";
    A.print();

    cout << "\nB:\n";
    B.print();

    Matrix<int> C = A + B;

    cout << "\nA + B:\n";
    C.print();

    return 0;
}

