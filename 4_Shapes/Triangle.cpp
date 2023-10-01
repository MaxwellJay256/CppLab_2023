#include "Shape.h"

Triangle::Triangle()
{
	vertices[0] = Point(0, 0);
	vertices[1] = Point(0, 0);
	vertices[2] = Point(0, 0);
}

Triangle::Triangle(Point A, Point B, Point C)
{
	// 检查是否为三角形。由于给的是三个顶点，所以只需检查三点是否共线即可。
	// 三点共线的条件是：三角形的面积为0
	vertices[0] = A;
	vertices[1] = B;
	vertices[2] = C;
	if (area() == 0)
	{
		cout << "Triangle(): " << endl;
		cout << A << " " << B << " " << C << endl;
		cout << "Is not a triangle!" << endl;
		exit(1);
	}
}

Triangle::~Triangle()
{
}

float Triangle::area() const
{
	// 使用海伦公式计算三角形面积
	float a = vertices[0].distance(vertices[1]);
	float b = vertices[1].distance(vertices[2]);
	float c = vertices[2].distance(vertices[0]);
	float s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

ostream& operator<<(ostream& os, const Triangle& t)
{
	os << "Triangle: " << t.vertices[0] << ", " << t.vertices[1] << ", " << t.vertices[2];
	return os;
}
