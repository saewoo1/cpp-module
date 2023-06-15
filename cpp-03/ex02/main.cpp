#include "FragTrap.hpp"

int	main(void) {
	FragTrap a("JJAK");
	FragTrap b("SSSSSCAV");

	a.attack("SSSSSCAV");
	b.takeDamage(30);
	b.beRepaired(30);
	b.attack("JJAK");
	a.takeDamage(10);
	a.beRepaired(10);
}