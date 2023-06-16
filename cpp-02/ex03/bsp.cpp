#include "Point.hpp"

static float area(Point a, Point b, Point c) {
	float area1;
	float area2;
	float res;

	area1 = (a.getX().toFloat() * b.getY().toFloat()
				+ b.getX().toFloat() * c.getY().toFloat()
				+ c.getX().toFloat() * a.getY().toFloat());
	area2 = (b.getX().toFloat() * a.getX().toFloat()
				+ c.getX().toFloat() * b.getY().toFloat()
				+ a.getX().toFloat() * c.getY().toFloat());
	res = area1 - area2;
	if (res < 0)
		res = res * -1;
	return (res / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float	all_area, a_area, b_area, c_area;

	all_area = area(a, b, c);
	a_area = area(point, a, b);
	b_area = area(point, a, c);
	c_area = area(point, b, c);

	if (a_area + b_area + c_area == all_area)
		return (true);
	return (false);
}