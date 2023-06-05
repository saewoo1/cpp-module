#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->str = str;
}
Weapon::~Weapon(void)
{

}

const std::string &Weapon::getType(void) const
{
	return (this->str);
}

void Weapon::setType(std::string str)
{
	this->str = str;
}