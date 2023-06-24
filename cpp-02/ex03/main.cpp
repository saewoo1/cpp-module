#include "Point.hpp"

int	main(void)
{
	Point a;
	Point b(10.0, 0.0);
	Point c(0.0, 10.0);
	Point po(0, 0);

	if (bsp(a, b, c, po) == true)
		std::cout << "In Triangle~ "<< std::endl;
	else
		std::cout << "Out Triangle~~" << std::endl;
}