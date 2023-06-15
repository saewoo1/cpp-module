#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point(void);

		Point &operator=(const Point &point);

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};
std::ostream &operator<<(std::ostream &obj, Point const point);

#endif