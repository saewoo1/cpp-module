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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoint = obj.EnergyPoint;

	std::cout << "ScavTrap operator " << name << "called" << std::endl; 
	return (*this);
}

void ScavTrap::guardGate(void)
{
	if (!this->HitPoints || !this->EnergyPoint)
		std::cout << "ScavTrap " << this->name << " point is empty" << std::endl;
	else
	{
		std::cout<< "ScavTrap " << this->name << " guardgate is called" << std::endl;
		this->EnergyPoint--;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->HitPoints || !this->EnergyPoint)
		std::cout << "ScavTrap " << this->name << " point is empty" << std::endl;
	else {
		std::cout << "ScavTrap " << this->name << " attaks " << target << 
			", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}
