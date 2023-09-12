#include "Data.hpp"

#include <iostream>

int main() {
	Data *data1;
	Data *data2;

	uintptr_t raw;

	data1 = new Data;

	std::cout << "Data : " << data1 << std::endl;
	raw = serialize(data1);
	std::cout << "Raw data : " << raw <<std::endl;
	data2 = deserialize(raw);
	std::cout << "Deserialized data : " << data2 << std::endl;

	delete data1;
	return (0);
}