#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "Cat... "+ this->type + " constructor is called" << std::endl;
}
Cat::~Cat(void)
{
	std::cout << "Cat " << type << " destructor is called" << std::endl;
}
Cat::Cat(const Cat &obj)
{
	this->type = obj.type;
	std::cout << "Cat class " << this->type << " copy constructor is called" << std::endl;
}
Cat& Cat::operator=(const Cat &obj) {
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "nyang nyang nyang~" << std::endl; 
}

std::string Cat::getType(void) const {
	return (this->type);
}
