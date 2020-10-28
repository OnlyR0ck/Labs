#pragma once

#include <iostream>
#include <fstream>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Quadrilateral
{
private:
	Point* four_points = new Point[4];
public:
	string shapeName;
	void setPoints();
	void showPoints() const;
	void getPoints(Point*) const;
	Quadrilateral();
	Quadrilateral(Point*, string);
	Quadrilateral(string);
	~Quadrilateral();
};

class Parallelogram : public Quadrilateral
{
public:
	double square;
	virtual void Shape();
	virtual void Squareof();
	Parallelogram(string);
	Parallelogram();
};

class Rhombus : public Quadrilateral
{
public:
	Rhombus(string);
	Rhombus();
	double square;
	virtual void Shape();
	virtual void SquareOf();
};

class Square : public Rhombus
{
public:
	Square(string);
	Square();
	void Shape() override;
	void SquareOf() override;
};

class Rectangle : public Parallelogram
{
public:
	Rectangle();
	void Shape() override;
	void Squareof() override;
};

class Trapezoid : public Parallelogram
{
public:
	double mLine;
	Trapezoid();
	void Shape() override;
	void Squareof() override;
	void midLine();
};

double getDistance(Point, Point);

void writeToFile(Parallelogram& object);
void writeToFile(Rhombus& object);
void writeToFile(Trapezoid& object);
