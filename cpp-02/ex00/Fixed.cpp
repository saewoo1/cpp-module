#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->val = obj.getRawBits();
	return (*this);
}
Fixed::Fixed(const Fixed& obj) // 객체를 그대로 이용해서 복사 -> 메모리 낭비 방지, const로 읽기만 가능하게
{
	std::cout << "Copy constructor called" << std::endl;
	this->val = obj.getRawBits();
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}
