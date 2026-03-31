#pragma once
#include <exception>

namespace MyException {
	class exception :std::exception {
	public:
		const char* what() const noexcept override;
	};
}