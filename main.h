#pragma once
#include <iostream>
using namespace std;
class Date {
private:
    int day, month, year;
public:
    Date();
    Date(int d, int m, int y);
    void addDay();
    Date& operator++();      
    Date operator++(int);    
    Date& operator--();      
    Date& operator=(const Date& d);
    Date& operator+=(int days);
    Date& operator-=(int days);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& out, const Date& d);
};