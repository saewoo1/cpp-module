#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{

}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attack with his " << this->weapon.getType() << std::endl;
}