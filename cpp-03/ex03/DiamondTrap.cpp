#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name)
{
	ClapTrap::name = name + "_clap_name";
	this->AttackDamage = 30;
	std::cout << "Diamond default Constructor is called!!!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), FragTrap(), ScavTrap() {
	this->name = name;
	this->AttackDamage = 30;

	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor is called" << std::endl;
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->name << " destructor is called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj), name(obj.name) {
	std::cout << "DiamondTrap " << this->name << " copy constructor is called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	if (this != &obj) {
		this->name = obj.name;
		ClapTrap::name = obj.name + " _clap_name";
		this->HitPoints = obj.HitPoints;
		this->EnergyPoint = obj.EnergyPoint;
		this->AttackDamage = obj.AttackDamage;
	}

	std::cout << "DiamondTrap " << this->name << " copy operator is called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name is " << this->name
		 << " ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::printStatus(void) {
	std::cout << this->name << std::endl;
	std::cout << this->HitPoints << std::endl;
	std::cout << this->AttackDamage << std::endl;
	std::cout << this->EnergyPoint << std::endl;
	std::cout << ClapTrap::name << std::endl;
	std::cout << std::endl;

}