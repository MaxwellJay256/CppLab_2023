#include "Shape.h"

Circle::Circle() : center(Point(0, 0)), radius(0) {}

Circle::Circle(Point _center, float r) :
	center(_center), radius(r)
{}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

float Circle::area() const
{
	return M_PI * radius * radius;
}

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Cirlce: " << "Center = " << c.center	<< " Radius = " << c.radius << endl;
	return output;
}
