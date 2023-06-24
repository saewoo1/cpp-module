#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->val = obj.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->val = obj.getRawBits();
	return (*this);	
}
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}
void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}
Fixed::Fixed(int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->val = num << this->bit;
}
Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->val = roundf(num * (1 << this->bit));
}

int	Fixed::toInt(void) const
{
	return (this->val >> this->bit);
}
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->val) / (1 << this->bit));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed& obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}
bool Fixed::operator>(const Fixed& obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}
bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}
bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}
bool Fixed::operator==(const Fixed& obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}
bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed tmp(this->toFloat() + obj.toFloat());
	return (tmp);
}
Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed tmp(this->toFloat() - obj.toFloat());
	return (tmp);
}
Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed tmp(this->toFloat() * obj.toFloat());
	return (tmp);
}
Fixed Fixed::operator/(const Fixed& obj) const
{
	if (obj == 0) {
		std::cout << "divison by 0..? bye..\n"; 
		exit(1);
	}
	Fixed tmp(this->toFloat() / obj.toFloat());
	return (tmp);
}

Fixed &Fixed::operator++(void)
{
	this->val++;
	return (*this);
}
const Fixed Fixed::operator++(int)
{
	const Fixed tmp(*this);
	this->val++;
	return (tmp);
}
Fixed &Fixed::operator--(void)
{
	this->val--;
	return (*this);
}
const Fixed Fixed::operator--(int)
{
	const Fixed tmp(*this);
	this->val--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}
const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}
const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}