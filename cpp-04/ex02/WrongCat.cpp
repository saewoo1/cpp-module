#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "wrong cat";
	std::cout << "WrongCat " + this->type << " default constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
	this->type = obj.type;
	std::cout << "WrongCat " + this->type << " copy constructor is called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat " + this->type << " destructor is called\n";
}
WrongCat& WrongCat::operator=(const WrongCat &obj) {
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "wrong cat wrong cat wrong cat...\n";
}