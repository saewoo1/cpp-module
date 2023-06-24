#include "DiamondTrap.hpp"

int main()
{	
    DiamondTrap a("JJAK");
	DiamondTrap b(a);
    DiamondTrap c;

    a.printStatus();
    b.printStatus();
    c.printStatus();
	a.attack("stranger");
	b.takeDamage(33);
	b.beRepaired(30);
	b.attack("stranger");
	a.takeDamage(10);
	a.beRepaired(10);
	a.highFiveGuys();

}