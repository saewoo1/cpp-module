#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name)
{
	ClapTrap::name = name + " _clap_name";
	std::cout << "Diamond default Constructor is called!!!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), FragTrap(), ScavTrap() {
	this->name = name;
	this->AttackDamage = 30; // FragTrap::AttackDamage;

	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor is called" << std::endl;
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->name << " destructor is called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj), name(obj.name) {
	std::cout << "DiamondTrap " << this->name << " copy constructor is called" << std::endl; // attackdamage는 frag꺼 받아야되는디
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	this->name = obj.name;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;

	std::cout << "DiamondTrap " << this->name << " copy operator is called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmi(void) {
	std::cout << "DiamondTrap name is " << this->name
		 << " ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}
