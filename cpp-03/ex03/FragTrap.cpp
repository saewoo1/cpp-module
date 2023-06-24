#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "default";
	this->AttackDamage = 30;
	this->HitPoints = 100;
	this->EnergyPoint = 100;

	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->AttackDamage = 30;
	this->HitPoints = 100;
	this->EnergyPoint = 100;

	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;

}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoint = obj.EnergyPoint;

	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destructor is called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->AttackDamage = obj.AttackDamage;
		this->HitPoints = obj.HitPoints;
		this->EnergyPoint = obj.EnergyPoint;
	}

	std::cout << "FragTrap operator " << name << "called" << std::endl; 
	return (*this);
}

void FragTrap::highFiveGuys(void) {
	if (!this->HitPoints)
		std::cout << "FragTrap " << this->name << " is already died...." << std::endl;
	else	
	{
		this->EnergyPoint++;
		std::cout << "FragTrap " << this->name << " HIFIVE!!!!! +1 EnergyPoint!!! eng : " << this->EnergyPoint << std::endl; 
	}
}
