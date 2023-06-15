#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap a("JJAK");
	DiamondTrap b("SSSSSCAV");

	a.attack("SSSSSCAV");
	b.takeDamage(30);
	b.beRepaired(30);
	b.attack("JJAK");
	a.takeDamage(10);
	a.beRepaired(10);
}