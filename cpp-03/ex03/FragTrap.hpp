#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);
		~FragTrap(void);

		// void attack(const std::string &target);
		void highFiveGuys(void);
};

#endif