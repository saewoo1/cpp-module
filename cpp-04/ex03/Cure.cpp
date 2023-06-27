#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << this->type << " constructor is called\n";
}
Cure::~Cure() {
	// std::cout << this->type << " destructor is called\n";
}
Cure::Cure(Cure const &obj) : type(obj.getType()) {
	// std::cout << this->type << " copy constructor is called\n";
}
Cure & Cure::operator=(Cure const & obj) {
	// std::cout << obj.getType() << " assignment is called\n";
	return (*this);
}
std::string const& Cure::getType() const {
	return (this->type);
}
Cure* Cure::clone() const {
	Cure* tmp = new Cure;
	return (tmp);
}

void Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}