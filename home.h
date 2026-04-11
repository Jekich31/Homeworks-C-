#pragma once
#include <iostream>

template<typename T>
class UniquePtr {
private:
	T* ptr;

public:
	explicit UniquePtr(T* p = nullptr);
	~UniquePtr();

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	UniquePtr(UniquePtr&& other) noexcept;
	UniquePtr& operator=(UniquePtr&& other) noexcept;

	T& operator*();
	T* operator->();

	T* get() const;
	T* release();
	void reset(T* p = nullptr);
};

template<typename T>
class SharedPtr {
private:
	T* ptr;
	int* count;

	void release();

public:
	explicit SharedPtr(T* p = nullptr);
	~SharedPtr();

	SharedPtr(const SharedPtr& other);
	SharedPtr& operator=(const SharedPtr& other);

	T& operator*();
	T* operator->();

	int use_count() const;
	T* get() const;
};