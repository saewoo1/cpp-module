#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("saewoo");
	ClapTrap b("tokki");

	a.attack("tokki");
	b.takeDamage(99);
	b.beRepaired(3);
	b.attack("saewoo");
	a.takeDamage(2);
	a.beRepaired(10);
}