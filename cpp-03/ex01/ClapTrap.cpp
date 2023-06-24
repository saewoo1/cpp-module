#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "default";
	this->AttackDamage = 0;
	this->HitPoints = 10;
	this->EnergyPoint = 10;

	std::cout << "ClapTrap " << this->name <<  " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->AttackDamage = 0;
	this->HitPoints = 10;
	this->EnergyPoint = 10;
	
	std::cout << "ClapTrap " << this->name <<  " constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->AttackDamage = obj.AttackDamage;
		this->HitPoints = obj.HitPoints;
		this->EnergyPoint = obj.EnergyPoint;
	}
	std::cout << "ClapTrap operator " << name << "called" << std::endl; 
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoint = obj.EnergyPoint;

	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->HitPoints || !this->EnergyPoint) {
		std::cout << "ClapTrap " << this->name << " point is empty" << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << 
			", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->HitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is already dead... don't hit.." << std::endl;
		return ;
	}
	if (amount > this->HitPoints)
		this->HitPoints = 0;
	else
		this->HitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount 
		<< " damage, " << this->HitPoints << " Hit points is left" <<std::endl;
	if (!this->HitPoints)
		std::cout << "ClapTrap " << this->name << " is died" << std::endl;
}	

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->HitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is already dead... can't cure" << std::endl;
		return ;
	}
	if (!this->EnergyPoint)
	{
		std::cout << "ClapTrap " << this->name <<  "has empty energy... can't cure" << std::endl;
		return ;
	}
	else
	{
		this->HitPoints += amount;
		this->EnergyPoint--;
		std::cout << "ClapTrap " << this->name << " is repaired of " << amount 
				<< " and has " << this->HitPoints << " hitpoints" << std::endl;
	}
}
unsigned int ClapTrap::getDamage(void)
{
	return (this->AttackDamage);
}
