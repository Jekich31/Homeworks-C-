#pragma once
#include <iostream>
#include <exception>
#include <string>
class Exception : public std::exception {
protected:
	std::string message;
public:
	Exception(const std::string& msg) : message(msg) {}
	virtual ~Exception() noexcept {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class MathException : public Exception {
public:
	MathException(const std::string& msg) : Exception(msg) {}
};

class DivisionByZeroException : public MathException {
public:
	DivisionByZeroException() : MathException("Error: Division by zero!") {}
};

class OverflowException : public MathException {
public:
	OverflowException() : MathException("Error: Overflow occurred!") {}
};
class MemoryException : public Exception {
public:
	MemoryException(const std::string& msg) : Exception(msg) {}
};

class OutOfMemoryException : public MemoryException {
public:
	OutOfMemoryException() : MemoryException("Error: Not enough memory!") {}
};
class FileException : public Exception {
public:
	FileException(const std::string& msg) : Exception(msg) {}
};

class FileNotFoundException : public FileException {
public:
	FileNotFoundException() : FileException("Error: File not found!") {}
};

class FileReadException : public FileException {
public:
	FileReadException() : FileException("Error: Cannot read file!") {}
};