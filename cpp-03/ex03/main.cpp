#include "DiamondTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "**  NONAME  **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap yasuo("yasuo");
        DiamondTrap by(yasuo);
        std::cout << std::endl;
        by.attack("peter");
        by.beRepaired(100);
        by.takeDamage(200);

        by.highFiveGuys();
        by.guardGate();
        by.whoAmI();
		by.statusPrint();
    }
    std::cout << std::endl;
    std::cout << "**    STRING  **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap harry("harry");
        std::cout << std::endl;
        harry.attack("james");
        harry.beRepaired(100);
        harry.takeDamage(150);

        harry.highFiveGuys();
        harry.guardGate();
        harry.whoAmI();
		harry.statusPrint();
    }
    std::cout << std::endl;
    std::cout << "**    COPY    **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap james("james");
        std::cout << std::endl;
        DiamondTrap peter(james);
        std::cout << std::endl;

        peter.attack("peter");
        peter.beRepaired(100);
        peter.takeDamage(200);

        peter.highFiveGuys();
        peter.guardGate();
        peter.whoAmI();
		peter.statusPrint();
    }
    return (0);
}