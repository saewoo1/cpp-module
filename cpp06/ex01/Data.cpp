#include "Data.hpp"

Data::Data() {
	_str = "form";
}

Data::Data(const Data &obj) {
	_str = obj._str;
}

Data::~Data() {}

Data &Data::operator=(const Data &obj) {
	_str = obj._str;
	return *this;
}

