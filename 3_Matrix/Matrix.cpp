#include "Matrix.h"

Matrix_4x4::Matrix_4x4()
{
	for (int i = 0; i < 4; i++)
	{
		matrix[i][i] = 1;
		for (int j = i + 1; j < 4; j++)
		{
			matrix[i][j] = 0;
			matrix[j][i] = 0;
		}
	}
}

Matrix_4x4::Matrix_4x4(const double* m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix[i][j] = m[i * 4 + j];
}

Matrix_4x4::Matrix_4x4(const Matrix_4x4& m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			matrix[i][j] = m.matrix[i][j];
}

Matrix_4x4::~Matrix_4x4() {}

Matrix_4x4& Matrix_4x4::operator=(const Matrix_4x4& m)
{
	if (this == &m)
		return *this;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			matrix[i][j] = m.matrix[i][j];
	return *this;
}

Matrix_4x4& Matrix_4x4::operator=(const double* m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			matrix[i][j] = m[i * 4 + j];
	return *this;
}

Matrix_4x4 Matrix_4x4::operator+(const Matrix_4x4& m)
{
	Matrix_4x4 temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
	return temp;
}

Matrix_4x4 Matrix_4x4::operator-(const Matrix_4x4& m)
{
	Matrix_4x4 temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			temp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
	return temp;
}

Matrix_4x4 Matrix_4x4::operator*(const Matrix_4x4& m)
{
	Matrix_4x4 temp;
	for (int i = 0; i < 4; i++) {
		temp.matrix[i][i] = 0;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				temp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
	}
	
	return temp;
}

Matrix_4x4 Matrix_4x4::operator^(const int i)
{
	Matrix_4x4 temp;
	if (i <= -1)
	{
		temp = this->inverse();
		temp = temp ^ (-i);
		return temp;
	}
	if (i == 0)
		return temp;
	temp = *this;

	for (int j = 1; j < i; j++)
		temp = temp * *this;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Matrix_4x4& m)
{
	for (int i = 0; i < 4; i++)
	{
		os << "| ";
		for (int j = 0; j < 4; j++)
			os << std::setprecision(6) << m.matrix[i][j] << " ";
		os << "|" << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix_4x4& m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			is >> m.matrix[i][j];
	return is;
}

void Matrix_4x4::swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

Matrix_4x4 Matrix_4x4::inverse()
{
	Matrix_4x4 temp;
	double det = this->det();
	if (det == 0)
	{
		std::cout << "Inverse: The matrix is singular!" << std::endl;
		return temp;
	}
	// 使用高斯-若尔当消元法求逆矩阵
	// 1. 将原矩阵和单位矩阵拼接成一个大矩阵
	double bigMatrix[4][8]{};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j < 4)
				bigMatrix[i][j] = matrix[i][j];
			else
				bigMatrix[i][j] = 0;
		}
		bigMatrix[i][i + 4] = 1;
	}
	// 2. 高斯-若尔当消元法
	for (int i = 0; i < 4; i++)
	{
		// 如果对角线元素为0，则交换行
		if (bigMatrix[i][i] == 0)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (bigMatrix[j][i] != 0)
				{
					for (int k = 0; k < 8; k++)
					{
						swap(bigMatrix[i][k], bigMatrix[j][k]);
					}
					break;
				}
			}
		}
		// 消元
		for (int j = 0; j < 4; j++)
		{
			if (j != i)
			{
				double ratio = bigMatrix[j][i] / bigMatrix[i][i];
				for (int k = 0; k < 8; k++)
					bigMatrix[j][k] -= bigMatrix[i][k] * ratio;
			}
		}
	}
	// 将大矩阵右半部分提取出来，即为逆矩阵
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			temp.matrix[i][j] = bigMatrix[i][j + 4] / det;
	return temp;
}

Matrix_4x4 Matrix_4x4::transpose()
{
	Matrix_4x4 temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			temp.matrix[i][j] = matrix[j][i];
	return temp;
}

double Matrix_4x4::det()
{
	double det = 1;
	// 使用高斯消去法，通过行变换将矩阵化为上三角矩阵
	for (int row = 0; row < 4; row++)
	{
		for (int i = row + 1; i < 4; i++)
		{
			if (matrix[i][row] > matrix[row][row])
			{
				for (int j = 0; j < 4; j++)
				{
					swap(matrix[i][j], matrix[row][j]);
				}
			}
		}
		// 如果主对角线上元素为0，则行列式为0
		if (matrix[row][row] == 0)
			return 0;
		// 消元
		for (int i = row + 1; i < 4; i++)
		{
			double ratio = matrix[i][row] / matrix[row][row];
			for (int j = 0; j < 4; j++)
				matrix[i][j] -= matrix[row][j] * ratio;
		}

		det *= matrix[row][row];
	}

	return det;
}