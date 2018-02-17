#pragma once
#include <exception>

using namespace std;

class IndexOutOfBoundsException: public exception {
public:
	IndexOutOfBoundsException(const char * message): exception(message) {}
};