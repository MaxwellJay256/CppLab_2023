#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
	/// @brief 虚函数，形状的面积
	virtual float area() const { return 0.0; }
	/// @brief 虚函数，体积
	virtual float volume() const { return 0.0; }
	/// @brief 纯虚函数，形状名称
	virtual void shapeName() const = 0;
};

class Point : public Shape
{
protected:
	float x, y;
	
public:
	Point(float _x = 0, float _y = 0);
	~Point();
	
	void setPoint(float _x, float _y);
	/// @brief 点的 x 坐标
	/// @return x
	float getX() const { return x; }
	/// @brief 点的 y 坐标
	/// @return y
	float getY() const { return y; }
	virtual void shapeName() const { cout << "Point: "; }// 对纯虚函数进行定义
	
	friend ostream &operator<<(ostream &, const Point &);
	// 重载运算符
	Point operator+(const Point &) const;
	Point operator-(const Point &) const;
	/// @brief 计算两点之间的距离
	/// @param p
	float distance(const Point &) const;
};

class Circle : public Shape
{
private:
	Point center; // 圆心
	float radius; // 半径

public:
	Circle();
	Circle(Point _center, float r = 0);
	~Circle() {}
	
	void setRadius(float);
	float getRadius() const;
	float area() const;
	void shapeName() const { cout << "Circle: "; }// 对纯虚函数进行再定义
	friend ostream &operator<<(ostream &, const Circle &);
};

class Triangle : public Shape
{
private:
	Point vertices[3];
	
public:
	Triangle();
	Triangle(Point, Point, Point);
	~Triangle();
	
	float area() const;
	void shapeName() const { cout << "Triangle: "; }
	friend ostream &operator<<(ostream &, const Triangle &);
};

class Rectangle : public Shape
{
private:
	Point vertices[4];
	
public:
	/// @brief 默认构造一个原点为左下角的矩形
	Rectangle();
	/// @brief 从 4 个点构造矩形。点的顺序必须沿顺时针或逆时针。
	Rectangle(Point, Point, Point, Point);
	~Rectangle();
	
	float area() const;
	void shapeName() const { cout << "Rectangle: "; }
	friend ostream &operator<<(ostream &, const Rectangle &);
};
