#include "exception.h"
const char* MyException::exception::what() const noexcept  {

	return "My very very very very very very very unexpected exception\n";
}