#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	private:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &obj);

		void makeSound(void);
		std::string getType(void) const;

};

#endif