#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal {
	private:
		std::string type;
		Brain *brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);

		void makeSound(void) const;
		std::string getType(void) const;
		Brain *getBrain(void) const;
};


#endif