#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap a("JJAK");
	ScavTrap b("SSSSSCAV");

	a.attack("SSSSSCAV");
	b.takeDamage(3);
	b.beRepaired(3);
	b.attack("JJAK");
	a.takeDamage(10);
	a.beRepaired(10);
}