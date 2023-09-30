#include <iostream>
#include "Matrix.h"

using namespace std;

int main(void)
{
	double m[4][4] = 
	{
		{ 1, 2, 3, 4 },
		{ 8, 6, 7, 9 },
		{ 4, 10, -4, 12 },
		{ -13, 14, 45, 28 },
	};

	// 测试构造函数
	Matrix_4x4 a;
	Matrix_4x4 b(a);
	Matrix_4x4 c(*m);
	Matrix_4x4 d;

	// 测试下标重载
	for (int i = 0; i < 4; i++)
	{
		for (int j=0; j< 4; j++)
			d[i][j] = m[i][j];
	}

	// 测试输入输出
	cout << "a = " << endl << a << endl;
	cout << "b(a) = " << endl << b << endl;
	cout << "c(*m) = " << endl << c << endl;
	cout << "d = " << endl << d << endl;

	// 测试算术运算符重载
	d = a + c;
	cout << "d = a + c = " << endl << d << endl;

	d = d - a;
	cout << "d = d - a = " << endl << d << endl;

	// 测试转置、求逆等运算
	d = d * d.inverse();
	cout << "d = d * d.inverse() = " << endl << d << endl;

	d = a ^ 3;
	cout << "d = a ^ 3 = " << endl << d << endl;

	d = c.transpose();
	cout << "d = c.transpose() = " << endl << d << endl;

	double e[4][4] =
	{
		{ 1, 2, 3, 5 },
		{ 6, 3, 2, 1 },
		{ 4, 3, 5, 2 },
		{ 6, 1, 3, 8 },
	};

	d = *e;
	cout << "d = e ^ 2 = " << endl << (d^2) << endl;
	cout << "d = e ^(-2) = " << endl << (d^(-2)) << endl;

	system("pause");
	return 0;
}