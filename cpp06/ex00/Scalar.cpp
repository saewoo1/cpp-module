#include "Scalar.hpp"
#include <cmath>
#include <iomanip>
#include <cstring>
#include <sstream>

Scalar::Scalar() {}

Scalar::~Scalar() {}

Scalar::Scalar(const Scalar &obj) {
	*this = obj;
}

Scalar& Scalar::operator=(const Scalar &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void Scalar::convert(const std::string &input) {
	printChar(input);
	printInt(input);
	printFloat(input);
	printDouble(input);
}

double Scalar::convertString(const std::string &input) {
	double num = 0.0;

	std::istringstream iss(input);
	return num;
}

void Scalar::printChar(const std::string &literal) {
	int num;

	if (literal ==  "nan" || literal == "nanf" || literal == "-inff" || literal == "-inf" || literal == "+inff" || literal == "+inf")
		std::cout << "char: impossible" << std::endl;
	else if(isdigit(literal[0] || literal[0] == '-')) {
		if (literal[literal.length() - 1] == 'f') {
			num = static_cast<int>(convertString(literal.substr(0, literal.length() - 1)));
			std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
		}
		else {
			num = static_cast<int>(convertString(literal));
			if ((num >= 0 && num <= 31) || num == 127)
				std::cout << "char: Non displayable" << std::endl;
			else if(num >= 32 && num <= 126)
				std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
		}
	}
}

void Scalar::printInt(const std::string &literal) {
	long num;

	if (literal ==  "nan" || literal == "nanf" || literal == "-inff" || literal == "-inf" || literal == "+inff" || literal == "+inf")
		std::cout << "int: impossible" << std::endl;
	else if(isdigit(literal[0]) || literal[0] == '-') {
		if(literal[literal.length() - 1] == 'f') {
			num = static_cast<int>(convertString(literal.substr(0, literal.length() - 1)));
			std::cout << "int: " << num << std::endl;
		}
		else {
			num = static_cast<long>(convertString(literal));
			if (num > 2147483647 || num < -2147483648)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << num << std::endl;
		}
	}
}

void Scalar::printFloat(const std::string& literal) {
	float num;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		std::cout << "float: impossible" << std::endl;
	else if(literal == "nan" || literal == "-inf" || literal == "+inf")
		std::cout << "float: " << literal + 'f' << std::endl;
	else if(isdigit(literal[0]) || literal[0] == '-') {
		if (literal[literal.length() - 1] == 'f')
			std::cout << "float: " << literal << std::endl;
		else {
			num = static_cast<float>(convertString(literal));
			std::cout << std::fixed << "float: " << std::setprecision(1) << num << "f" << std::endl;
		}
	}
}

void Scalar::printDouble(const std::string& literal) {
	double num;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		std::cout << "double: impossible" << std::endl;
	else if(literal == "nan" || literal == "-inf" || literal == "+inf")
		std::cout << "double: " << literal + 'f' << std::endl;
	else if(isdigit(literal[0]) || literal[0] == '-') {
		if(literal[literal.length() - 1] == 'f') {
			std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		}
		else {
			num = static_cast<double>(convertString(literal));
			std::cout << std::fixed << "double: " << std::setprecision(1) << num << std::endl;
		}
	}
}