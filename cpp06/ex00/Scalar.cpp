#include "Scalar.hpp"
#include <math.h>
#include <cstdlib>
#include <cctype>
#include <cfloat>

Scalar::Scalar(){}

Scalar::Scalar(const Scalar &obj) {
	static_cast<void>(obj);
}

Scalar &Scalar::operator=(const Scalar &obj) {
	if (this != &obj) {
		return *this;
	}
	return *this;
}

Scalar::~Scalar() {}

bool findPoint(std::string str) {
	size_t i = str.find('.');

	try {
		while(str.at(++i) == '0')
			;
		if (std::isdigit(str.at(i)))
			return false;
	} catch(std::exception &e) {}
	return true;
}

void Scalar::convertChar(double _double) {
	if (isnan(_double) || isinf(_double) || _double < 0 || _double > 127) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(_double)) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(_double) << "'" << std::endl;
}

void Scalar::convertInt(double _double){
	if (isnan(_double) || isinf(_double) || _double < INT_MIN || _double > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(_double) << std::endl;
}

void Scalar::convertFloat(double _double) {
	if (errno == ERANGE || (!isinf(_double) && (_double < -FLT_MAX || _double > FLT_MAX))) {
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float _float = static_cast<float>(_double);
	std::cout << "float: " << _float;
	if (!isnan(_float) && !isinf(_float) && (std::to_string(_double).find('.') == std::string::npos || findPoint(std::to_string(_double))))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void Scalar::convertDouble(double _double){
	if (errno == ERANGE) {
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	std::cout << "double: " << _double;
	if (!isnan(_double) && !isinf(_double) && (std::to_string(_double).find('.') == std::string::npos || findPoint(std::to_string(_double))))
		std::cout << ".0";
	std::cout << std::endl;
}

void Scalar::convertAll(const std::string& arg) {
	std::string _str;
	try {
		_str = arg;
	} catch(std::bad_alloc &e) {
		std::cout << "Too big for Allocated.." << std::endl;
		exit(1);
	}
	
	if (_str.length() == 1 && !isdigit(_str[0])) {
		convertAscii(_str[0]);
		return ;
	}
	double _double = std::strtod(_str.c_str(), NULL);
	convertChar(_double);
	convertInt(_double);
	convertFloat(_double);
	convertDouble(_double);
}

void Scalar::convertAscii(char c) {
	if (isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) <<".0f" << std::endl; 
		std::cout << "double: " << static_cast<double>(c) <<".0" << std::endl; 
	}
}