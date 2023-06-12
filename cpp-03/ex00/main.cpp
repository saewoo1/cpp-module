#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("saewoo");
	ClapTrap b("tokki");

	a.attack("tokki");
	b.takeDamage(3);
	b.beRepaired(3);
	b.attack("saewoo");
	a.takeDamage(10);
	a.beRepaired(10);
}