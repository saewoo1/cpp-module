#include "Scalar.hpp"

Scalar::Scalar() {}

Scalar::Scalar(const Scalar &obj) {*this = obj;}

Scalar& Scalar::operator=(const Scalar &obj) {
	return *this;
}

void Scalar::ScalarConverter(const std::string &literal) {
	std::string pseudoType[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	// toChar
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double:" << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return ;
	}

	// string -> c-style string.직접 접근, null 문자 포함
	toInt = std::atoi(literal.c_str());

	if (literal[literal.length() - 1] == 'f') {
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	} else {
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	// 의사타입인지 판별돌기
	for (int i = 0; i < 6; i++) {
		if (literal == pseudoType[i]) {
			toChar = "impossible";
			break;
		}
	}

	//int가 출력 가능한 문자인지 판별하기
	if (toChar == "" && std::isprint(toInt)) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} else if (toChar == "") {
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	if (toChar == "impossible") {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "impossible" && toFloat == 0) {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} else {
		if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0) {
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} else {
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}