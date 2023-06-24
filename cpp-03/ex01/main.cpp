#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap a("JJAK");
	ScavTrap b("SSSSSCAV");

	a.attack("SSSSSCAV");
	b.takeDamage(999);
	b.beRepaired(3);
	b.attack("JJAK");
	a.takeDamage(10);
	a.beRepaired(10);
	b.takeDamage(2);
	a.guardGate();
}