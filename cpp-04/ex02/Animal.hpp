#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal // 순수 가상함수를 포함 -> 추상클래스 Animal, 상속받는 애들은 반드시 이를 재정의해야한다.
{
	protected:
		std::string	type;
	public:
		Animal(void);
		virtual ~Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif