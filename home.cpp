#include "home.h"

template<typename T>
UniquePtr<T>::UniquePtr(T* p) : ptr(p) {}

template<typename T>
UniquePtr<T>::~UniquePtr() {
	delete ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept {
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept {
	if (this != &other) {
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template<typename T>
T& UniquePtr<T>::operator*() {
	return *ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() {
	return ptr;
}

template<typename T>
T* UniquePtr<T>::get() const {
	return ptr;
}

template<typename T>
T* UniquePtr<T>::release() {
	T* temp = ptr;
	ptr = nullptr;
	return temp;
}

template<typename T>
void UniquePtr<T>::reset(T* p) {
	delete ptr;
	ptr = p;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* p) {
	ptr = p;
	if (p) count = new int(1);
	else count = nullptr;
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
	release();
}

template<typename T>
void SharedPtr<T>::release() {
	if (count) {
		(*count)--;
		if (*count == 0) {
			delete ptr;
			delete count;
		}
	}
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) {
	ptr = other.ptr;
	count = other.count;
	if (count) (*count)++;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other) {
	if (this != &other) {
		release();
		ptr = other.ptr;
		count = other.count;
		if (count) (*count)++;
	}
	return *this;
}

template<typename T>
T& SharedPtr<T>::operator*() {
	return *ptr;
}

template<typename T>
T* SharedPtr<T>::operator->() {
	return ptr;
}

template<typename T>
int SharedPtr<T>::use_count() const {
	return count ? *count : 0;
}

template<typename T>
T* SharedPtr<T>::get() const {
	return ptr;
}

class Test;

template class UniquePtr<Test>;
template class SharedPtr<Test>;