#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0){}
};
class LinearEquation
{
private:
	Point one;
	Point two;
public:
	LinearEquation();
	LinearEquation(int, int, int, int);
	void setPoint();
	void getPoint(Point*, Point*);
	void showPoints()const;
	void showEquation();
	void calculateY();
};

void menu();
void logger(int, LinearEquation);
int correct_user_input();

ostream& setwandfill(ostream& stream);