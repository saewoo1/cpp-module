#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal... "+ this->type + " constructor is called" << std::endl;
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << type << " destructor is called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->type = obj.type;
	std::cout << "WrongAnimal class " << this->type << " copy constructor is called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj) {
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "wrong wrong wrong~~~~" << std::endl; 
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}