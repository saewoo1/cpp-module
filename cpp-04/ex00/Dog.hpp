#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal {
	private:
		std::string type;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);

		void makeSound(void) const;
		std::string getType(void) const;
};


#endif