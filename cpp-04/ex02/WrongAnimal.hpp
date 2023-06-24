#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &obj);

		void makeSound(void) const; // WrongAnimal꺼는 virtual로 선언 안함 -> 부모꺼 호출로 잡음
		std::string getType(void) const;

};

#endif