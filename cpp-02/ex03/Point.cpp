#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}
Point::Point(const float x, const float y) : x(x), y(y) {
}
Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY()) {
}
Point::~Point(void)
{

}
Point& Point::operator=(const Point &point) {
	if (this != &point) {
		const_cast<Fixed&>(x) = point.getX();
		const_cast<Fixed&>(y) = point.getY();
	}
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return (this->x);
}

const Fixed &Point::getY(void) const
{
	return (this->y);
}
