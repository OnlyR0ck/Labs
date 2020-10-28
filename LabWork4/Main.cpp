#include <iostream>
#include "Shapes.h"
#include "../HelperLib/HelperLib.h"

void EnterData(Quadrilateral* arr);
void SetUp();

int main()
{
	/*delegate arr[1];
	arr[0] = SetUp;
	string names[1]*/
	delegate* arr = new delegate{ SetUp };
	string* names = new string[2];
	names[0] = "Enter data and wrote calculations to the file.";
	names[1] = "Exit";
	//names[0] = "Enter data and wrote calculations to the file.";
	Menu(arr, 2, names);
	return 0;
}

void SetUp()
{
	Quadrilateral* shapes = new Quadrilateral[5];
	Parallelogram par;
	Rhombus rhombus;
	Square sq;
	Trapezoid trapezoid;
	class Rectangle rectangle;
	shapes[0] = par;
	shapes[1] = rhombus;
	shapes[2] = sq;
	shapes[3] = rectangle;
	shapes[4] = trapezoid;
	EnterData(shapes);
	par.Squareof();
	rhombus.SquareOf();
	sq.SquareOf();
	rectangle.Squareof();
	trapezoid.Squareof();
	trapezoid.midLine();
	writeToFile(par);
	writeToFile(sq);
	writeToFile(trapezoid);
	writeToFile(rhombus);
	writeToFile(rectangle);
}

void EnterData(Quadrilateral* arr)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter points for " << arr[i].shapeName << endl;
		arr[i].setPoints();
	}
}
