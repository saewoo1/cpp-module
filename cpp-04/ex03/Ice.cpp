#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << this->type << " constructor is called\n";
}
Ice::~Ice() {
	// std::cout << this->type << " destructor is called\n";
}
Ice::Ice(Ice const &obj) : type(obj.getType()) {
	// std::cout << this->type << " copy constructor is called\n";
}
Ice & Ice::operator=(Ice const & obj) {
	// std::cout << obj.getType() << " assignment is called\n";
	return (*this);
}
std::string const& Ice::getType() const {
	return (this->type);
}
Ice* Ice::clone() const {
	Ice* tmp = new Ice;
	return (tmp);
}

void Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}