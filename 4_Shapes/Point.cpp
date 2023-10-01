#include "Shape.h"

Point::Point(float _x, float _y) : x(_x), y(_y)
{
}

Point::~Point()
{
}

void Point::setPoint(float _x, float _y)
{
	x = _x;
	y = _y;
}

ostream &operator<<(ostream &os, const Point &p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

Point Point::operator+(const Point&p) const
{
	return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point& p) const
{
	return Point(x - p.x, y - p.y);
}

float Point::distance(const Point& p) const
{
	return hypotf((x - p.getX()), (y - p.getY()));
}
