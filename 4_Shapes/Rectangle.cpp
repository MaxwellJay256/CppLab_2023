#include "Shape.h"

Rectangle::Rectangle()
{
	vertices[0].setPoint(0, 0);
	vertices[1].setPoint(1, 0);
	vertices[2].setPoint(1, 1);
	vertices[3].setPoint(0, 1);
}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4)
{
	// 检查是否为矩形。矩形不一定横平竖直。
	// 1. 任意两条对边相等
	// 2. 对角线相等
	if (p1.distance(p2) != p3.distance(p4) || p1.distance(p4) != p2.distance(p3) 
		|| p1.distance(p3) != p2.distance(p4))
	{
		cout << "Rectangle(): " << endl;
		cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
		cout << "Is not a rectangle!" << endl;
		exit(1);
	}
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
	vertices[3] = p4;
}

Rectangle::~Rectangle()
{
}

float Rectangle::area() const
{
	float a = vertices[0].distance(vertices[1]);
	float b = vertices[1].distance(vertices[2]);
	return a * b;
}

ostream& operator<<(ostream& os, const Rectangle& p)
{
	os << "Rectangle: " << endl;
	os << p.vertices[0] << "\t" << p.vertices[1] << endl;
	os << p.vertices[2] << "\t" << p.vertices[3] << endl;
	return os;
}