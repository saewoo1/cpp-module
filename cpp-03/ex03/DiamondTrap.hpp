#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap { // Frag, scav를 같이 상속 받기. 여기에 쓰인 마지막 값이 덮어씌워진대..
	private:
		std::string name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);

		void whoAmI(void);
		void attack(const std::string &target);
		void statusPrint(void);
};

#endif