#pragma once
#include <iostream>
template <typename T>
class Box {
	T value;
public:
	Box();
	Box(T value);
	template <typename U>
	friend std::istream& operator>>(std::istream& is, Box<U>& box);
	T get() const;
	
};

template <typename T>
Box<T>::Box() :value() {}

template <typename T>
Box<T>::Box(T value) : value(value) {}

template <typename T>
T Box<T>::get() const {
	return this->value;
}

template <typename U>
std::istream& operator>>(std::istream& is, Box<U>& box) {
	is >> box.value;
	return is;
}