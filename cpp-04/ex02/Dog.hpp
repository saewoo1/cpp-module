#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal {
	private:
		std::string type;
		Brain *brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);

		void makeSound(void) const;
		std::string getType(void) const;
		Brain *getBrain(void) const;
};


#endif