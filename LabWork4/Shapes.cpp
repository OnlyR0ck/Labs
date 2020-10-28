#include "Shapes.h"

Quadrilateral::Quadrilateral()
{
	shapeName = "Quadriteral";
	Point temp;
	temp.x = temp.y = 0;
	for (int i = 0; i < 4; i++)
	{
		four_points[i] = temp;
	}
}

Quadrilateral::Quadrilateral(Point* temp, string name)
{
	this->shapeName = name;
	for (int i = 0; i < 4; i++)
	{
		four_points[i] = temp[i];
	}
}

Quadrilateral::Quadrilateral(string name)
{
	shapeName = name;
}

Quadrilateral::~Quadrilateral()
{
	delete[] four_points;
}

void Quadrilateral::setPoints()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter " << i + 1 << " X coordinate: ";
		cin >> four_points[i].x;
		cout << "Enter " << i + 1 << " Y coordinate: ";
		cin >> four_points[i].y;
	}
}

void Quadrilateral::showPoints() const
{
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ".(" << four_points[i].x << ", " << four_points[i].y << ")" << endl;
	}
}

void Quadrilateral::getPoints(Point* points) const
{
	for(int i = 0;i<4;i++)
	{
		points[i] = four_points[i];
	}
}

Rhombus::Rhombus(string name) : Quadrilateral(name)
{
	square = 0;
}

Rhombus::Rhombus()
{
	square = 0;
	shapeName = "Rhombus";
}

void Rhombus::Shape()
{
	shapeName = "Rhombus";
}

void Rhombus::SquareOf()
{
	Point* arr = new Point[4];
	getPoints(arr);
	square = 0.5 * getDistance(arr[0], arr[2]) * getDistance(arr[1], arr[3]);
}

Square::Square(string name) : Rhombus(name)
{
}

Square::Square()
{
	square = 0;
	shapeName = "Square";
}

void Square::Shape()
{
	shapeName = "Square";
}

void Square::SquareOf()
{
	Point* arr = new Point[4];
	getPoints(arr);
	square = getDistance(arr[0], arr[1]) * getDistance(arr[1], arr[2]);
}

void Parallelogram::Shape()
{
	shapeName = "Parallelogram";
}

void Parallelogram::Squareof()
{
	auto* arr = new Point[4];
	getPoints(arr);
	double height = fabs(arr[1].y - arr[0].y);
	square = (arr[0].x - arr[1].x) * (arr[0].x - arr[1].x) * height;
}

Parallelogram::Parallelogram(string name) : Quadrilateral(name)
{
	square = 0;
}

Parallelogram::Parallelogram()
{
	shapeName = "Parallelogram";
	square = 0;
}

Rectangle::Rectangle() : Parallelogram()
{
	shapeName = "Rectangle";
	square = 0;
}

void Rectangle::Shape()
{
	cout << "I'm a Rectangle" << endl;
}

void Rectangle::Squareof()
{
	auto* arr = new Point[4];
	getPoints(arr);
	square = getDistance(arr[0], arr[1]) * getDistance(arr[1], arr[2]);
}

Trapezoid::Trapezoid()
{
	shapeName = "Trapezoid";
	square = 0;
	mLine = 0;
}

void Trapezoid::Shape()
{
	cout << "I'm a Trapezoid" << endl;
}

void Trapezoid::Squareof()
{
	Point* arr = new Point[4];
	getPoints(arr);
	square = (getDistance(arr[1], arr[2]) + getDistance(arr[0], arr[3])) * (arr[1].y - arr[2].y) * 0.5;
}

void Trapezoid::midLine()
{
	Point* arr = new Point[4];
	getPoints(arr);
	mLine = (getDistance(arr[0], arr[3]) + getDistance(arr[1], arr[2])) * 0.5;
}

double getDistance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void writeToFile(Parallelogram& object)
{
	ofstream fout;
	fout.open("Shapes info", ios::app);
	if (fout.is_open())
	{
		Point* arr = new Point[4];
		object.getPoints(arr);

		fout << object.shapeName << endl;
		fout << "The coordinates is :" << endl;
		for (int i = 0; i < 4; i++)
		{
			fout << "Point " << i + 1 << " : " << arr[i].x << "," << arr[i].y << endl;
		}
		fout << "The square is " << object.square << endl;
	}
	fout.close();
}

void writeToFile(Rhombus& object)
{
	ofstream fout;
	fout.open("Shapes info", ios::app);
	if (fout.is_open())
	{
		Point* arr = new Point[4];
		object.getPoints(arr);

		fout << object.shapeName << endl;
		fout << "The coordinates is :" << endl;
		for (int i = 0; i < 4; i++)
		{
			fout << "Point " << i + 1 << " : " << arr[i].x << "," << arr[i].y << endl;
		}
		fout << "The square is " << object.square << endl;
	}
	fout.close();
}

void writeToFile(Trapezoid& object)
{
	ofstream fout;
	fout.open("Shapes info", ios::app);
	if (fout.is_open())
	{
		Point* arr = new Point[4];
		object.getPoints(arr);
		fout << object.shapeName << endl;
		fout << "The coordinates is :" << endl;
		for (int i = 0; i < 4; i++)
		{
			fout << "Point " << i + 1 << " : " << arr[i].x << "," << arr[i].y << endl;
		}
		fout << "The square is " << object.square << endl;
		fout << "The middle line of trapezoid is :" << object.mLine << endl;
	}
	fout.close();
}
