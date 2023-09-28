#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

// void leak(){
// 	system("leaks data");
// }

int main() {
	// atexit(leak);
	Data* originalData = new Data();
	uintptr_t raw = Serializer::serialize(originalData);

	Data* deserializedData = Serializer::deserialize(raw);

	bool isEqual = (originalData == deserializedData);

	std::cout << "Original! : " << originalData << std:: endl;
	std::cout << "After Serialized, raw data : " << raw << std::endl;
	std::cout << "After Deserialized : " << deserializedData << std::endl;;

	std::cout << "Equal? " << std::boolalpha << isEqual << std::endl;

	delete originalData;
	return (0);
}