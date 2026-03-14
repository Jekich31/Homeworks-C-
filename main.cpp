//домашнє завдання за 06.03
#include <iostream>
#include "main.h"
using namespace std;
int main() {
    Date d1, d2;
    cout << "Enter first date:\n";
    cin >> d1;
    cout << "Enter second date:\n";
    cin >> d2;
    cout << "Date 1: " << d1 << endl;
    cout << "Date 2: " << d2 << endl;
    ++d1;
    cout << "After ++ Date1: " << d1 << endl;
    if (d1 == d2)
        cout << "Dates are equal\n";
    else
        cout << "Dates are not equal\n";

    if (d1 > d2)
        cout << "Date1 is later\n";
    else
        cout << "Date1 is earlier or equal\n";
    return 0;
}
