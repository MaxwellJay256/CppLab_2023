#include "Shape.h"
#include <iostream>

using namespace std;

// 定义抽象基类Shape，由它派生出3个派生类： Circle、 Triangle、Rectangle。
// 用虚函数分别计算多个不同类图形的面积，并求它们的面积和。
// 要求用基类指针数组，使它的每一个元素指向一个派生类的对象，使用一个循环完成对多个图像的面积计算与求和。
// 图型的数据在定义对象时给定。

int main(void)
{
	//*/
	Shape* shapes[3]{};
	shapes[0] = new Circle(Point(0, 0), 1);
	shapes[1] = new Triangle(Point(0, 0), Point(1, 0), Point(0, 1));
	shapes[2] = new Rectangle(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));

	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		// 打印每个图形
		shapes[i]->shapeName();
		cout << shapes[i]->area() << endl;
		sum += shapes[i]->area();
	}
	cout << "Sum of area: " << sum << endl;
	//*/

	// 检查三角形错误的例子
	// Triangle t(Point(0, 0), Point(1, 0), Point(2, 0));
	// 检查矩形错误的例子
	// Rectangle r(Point(0, 0), Point(3, 0), Point(4, 2), Point(1, 2));

	system("pause");
	return 0;
}
