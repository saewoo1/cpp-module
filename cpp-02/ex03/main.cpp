#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a;
	Point b(10.0, 0.0);
	Point c(0.0, 10.0);
	Point po(1.0, 1.0);

	if (bsp(a, b, c, po) == true)
		std::cout << "In Triangle~ "<< std::endl;
	else
		std::cout << "Out Triangle~~" << std::endl;
}