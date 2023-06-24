#include "Point.hpp"

float calculate_alpha(Point const a, Point const b, Point const c, Point const p)
{
	return ((b.getY().toFloat() - c.getY().toFloat()) * (p.getX().toFloat() - c.getX().toFloat()) +
		(c.getX().toFloat() - b.getX().toFloat()) * (p.getY().toFloat() - c.getY().toFloat())) /
		((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) +
		(c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
}

float calculate_beta(Point const a, Point const b, Point const c, Point const p)
{
	return ((c.getY().toFloat() - a.getY().toFloat()) * (p.getX().toFloat() - c.getX().toFloat()) +
		(a.getX().toFloat() - c.getX().toFloat()) * (p.getY().toFloat() - c.getY().toFloat())) /
		((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) +
		(c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float alpha = calculate_alpha(a, b, c, point);
	float beta = calculate_beta(a, b, c, point);
	float gamma = 1.0f - alpha - beta;

	return 0 < alpha && 0 < beta && 0 < gamma;
}