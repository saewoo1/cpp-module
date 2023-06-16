#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		virtual ~Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif