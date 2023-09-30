#pragma once
#include <iostream>
#include <iomanip>

// 一个 4x4 矩阵类
class Matrix_4x4
{
private:
	double matrix[4][4];
	/// @brief 交换两个double类型的数值
	void swap(double& a, double& b);
public:
	/// @brief 默认构造函数，初始化矩阵为单位矩阵
	Matrix_4x4();
	/// @brief 带参数的构造函数，从一个4x4的数组初始化矩阵
	Matrix_4x4(const double* m);
	/// @brief 拷贝构造函数
	Matrix_4x4(const Matrix_4x4& m);
	/// @brief 析构函数
	~Matrix_4x4();

	/// @brief 重载=运算符，参数为矩阵对象
	Matrix_4x4& operator=(const Matrix_4x4& m);
	/// @brief 重载=运算符，参数为二维数组
	Matrix_4x4& operator=(const double* m);
	/// @brief 重载算术运算符 +
	Matrix_4x4 operator+(const Matrix_4x4& m);
	/// @brief 重载算术运算符 -
	Matrix_4x4 operator-(const Matrix_4x4& m);
	/// @brief 重载算术运算符 *
	Matrix_4x4 operator*(const Matrix_4x4& m);
	// 重载 ^ 运算符为矩阵的 i 次幂
	Matrix_4x4 operator^(const int i);
	/// @brief 重载 [] 运算符，实现双下标方式访问矩阵元素
	const double* operator[](const int i) const { return matrix[i]; }
	double* operator[](const int i) { return matrix[i]; }
	
	/// @brief 重载输入 <<
	friend std::ostream& operator<<(std::ostream& os, const Matrix_4x4& m);
	/// @brief 重载输出 >>
	friend std::istream& operator>>(std::istream& is, Matrix_4x4& m);

	/// @brief 矩阵求逆，不改变当前矩阵值，返回逆矩阵
	Matrix_4x4 inverse();
	/// @brief 矩阵转置，不改变当前矩阵值，返回转置矩阵
	Matrix_4x4 transpose();
	
	/// @brief 求矩阵行列式
	double det();
};