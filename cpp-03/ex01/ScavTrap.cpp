#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "default";
	this->AttackDamage = 20;
	this->HitPoints = 100;
	this->EnergyPoint = 50;

	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->AttackDamage = 20;
	this->HitPoints = 100;
	this->EnergyPoint = 50;

	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoint = obj.EnergyPoint;

	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}
