#include "main.h"
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void Date::addDay() {
    day++;
    if (day > 30) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        year++;
    }
}
Date& Date::operator++() {
    addDay();
    return *this;
}
Date Date::operator++(int) {
    Date temp = *this;
    addDay();
    return temp;
}
Date& Date::operator--() {
    day--;
    if (day < 1) {
        day = 30;
        month--;
    }
    if (month < 1) {
        month = 12;
        year--;
    }
    return *this;
}
Date& Date::operator=(const Date& d) {
    day = d.day;
    month = d.month;
    year = d.year;
    return *this;
}
Date& Date::operator+=(int days) {
    for (int i = 0; i < days; i++)
        addDay();
    return *this;
}
Date& Date::operator-=(int days) {
    for (int i = 0; i < days; i++)
        --(*this);
    return *this;
}
bool Date::operator==(const Date& d) {
    return day == d.day && month == d.month && year == d.year;
}
bool Date::operator!=(const Date& d) {
    return !(*this == d);
}
bool Date::operator>(const Date& d) {
    if (year > d.year) return true;
    if (year == d.year && month > d.month) return true;
    if (year == d.year && month == d.month && day > d.day) return true;
    return false;
}
bool Date::operator<(const Date& d) {
    return !(*this > d) && !(*this == d);
}
istream& operator>>(istream& in, Date& d) {
    cout << "Day: ";
    in >> d.day;
    while (d.day < 1 || d.day > 31) {
        cout << "Wrong month! Enter again: ";
        in >> d.day;
    }
    cout << "Month: ";
    in >> d.month;
    while (d.month < 1 || d.month > 12) {
        cout << "Wrong month! Enter again: ";
        in >> d.month;
    }
    cout << "Year: ";
    in >> d.year;
    while (d.year < 1900 || d.year > 2027) {
        cout << "Wrong year! Enter again: ";
        in >> d.year;
    }
    return in;
}
ostream& operator<<(ostream& out, const Date& d) {
    out << d.day << "." << d.month << "." << d.year;
    return out;
}