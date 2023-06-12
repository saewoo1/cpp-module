#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
		std::string name;
		unsigned int HitPoints;
		unsigned int EnergyPoint;
		unsigned int AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap &operator=(const ClapTrap &obj);
		virtual ~ClapTrap(void);

		virtual void attack(const std::string& target);
		unsigned int getDamage(void);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif