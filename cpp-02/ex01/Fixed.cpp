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

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->val = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->val = obj.getRawBits();
	return (*this);	
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

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->val = num << this->bit;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->val = roundf(num * (1 << this->bit));
}