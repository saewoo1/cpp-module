#include "Point.hpp"

Point::Point(void) : x(0), y(0) {

}
Point::Point(const float x, const float y) : x(x), y(y) {
	//엥.. toFloat 못쓰네..........
}
Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY()) {
	//copy 받아온 외부의 class의 값으로 x, y 값 세팅
}
Point::~Point(void)
{

}
Point& Point::operator=(const Point &point){
	if (this == &point) // 더 생각해봐야할듯.. 값을 바꿔줘야되는데 흠..
		return(*this);
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

std::ostream &operator<<(std::ostream &out, Point const point)
{
	out << "x : " << point.getX() << "y : " << point.getY() << std::endl;
	return (out);
}
