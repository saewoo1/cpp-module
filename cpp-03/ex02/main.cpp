#include "FragTrap.hpp"

int	main(void) {
	FragTrap a("JJAK");
	FragTrap b("FRRRRAAAAAG");

	a.attack("FRRRRAAAAAG");
	b.takeDamage(999);
	b.beRepaired(30);
	b.attack("JJAK");
	a.takeDamage(10);
	a.beRepaired(10);
	a.highFiveGuys();
}