#include "Lab_two.h"

#pragma once


LinearEquation::LinearEquation()
{
	one.x = one.y = two.x = two.y = 0;
}

LinearEquation::LinearEquation(int x1, int y1, int x2, int y2)
{
	one.x = x1;
	one.y = y1;
	two.x = x2;
	two.y = y2;
}

void LinearEquation::setPoint()
{
	cout << "Enter X1 : "; one.x = correct_user_input();
	cout << "Enter Y1 : "; one.y = correct_user_input();
	cout << "Enter X2 : "; two.x = correct_user_input();
	cout << "Enter Y2 : "; two.y = correct_user_input();
	_getch();
}

void LinearEquation::getPoint(Point* one, Point* two)
{
	one->x = this->one.x;
	one->y = this->one.y;
	two->x = this->two.x;
	two->y = this->two.y;
}

void LinearEquation::showPoints() const
{
	cout << "X1 : " << one.x << endl;
	cout << "Y1 : " << one.y << endl;
	cout << "X2 : " << two.x << endl;
	cout << "Y2 : " << two.x << endl;
	_getch();

}

void LinearEquation::showEquation()
{
	cout << "The linear equation is : ";
	cout << " (x - " << one.x << ")/" << two.x - one.x << " = " << "(y - " << one.y << ")/" << two.y - one.y << endl;
	_getch();
}

void LinearEquation::calculateY()
{
	int x, y;
	cout << "Enter x : "; x = correct_user_input();
	y = (x - one.x) * (two.y - one.y) / (two.x - one.x) + one.y;
	cout << "Than y is : " << setwandfill << y << endl;
	_getch();

}

void menu()
{
	LinearEquation equation;
	int code;
	while (true)
	{
		cout << "1 - Enter data about points.\n2 - Show Points.\n3 - Show Equation.\n4 - Solve Equation.\n0 - Exit." << endl;
		cout << "Your choice : "; code = correct_user_input();
		switch (code)
		{
		case 1:
			equation.setPoint();
			logger(code, equation);
			break;
		case 2:
			equation.showPoints();
			logger(code, equation);
			break;
		case 3:
			equation.showEquation();
			logger(code, equation);
			break;;
		case 4:
			equation.calculateY();
			logger(code, equation);
			break;
		case 0:
			exit(0);
			logger(code, equation);
			break;
		default:
			system("cls");
			logger(code, equation);
			break;
		}

		system("cls");

	}
}

ostream& setwandfill(ostream& stream)
{
	stream << setw(10) << setfill('%') << setprecision(4);
	return stream;
}

int correct_user_input()
{
	int value;
	while (!(cin >> value) or cin.get() != '\n')
	{
		cout << "Incorrect user input, try again : ";
		cin.clear();
		while (cin.get() != '\n');
	}
	return value;
}

void logger(int code, LinearEquation eq)
{
	ofstream fout;
	Point a, b ;
	a.x = a.y = b.x = b.y = 0;
	fout.open("Debug.txt", ios::app);
	if (fout.is_open())
	{
		switch (code)
		{
		case 1:
			
			fout << "User was set points : " << endl;
			eq.getPoint(&a, &b);
			fout << "X1: " << a.x << endl;
			fout << "Y1: " << a.y << endl;
			fout << "X2: " << b.x << endl;
			fout << "Y2: " << b.y << endl;
			break;
		case 2:
			fout << "The user viewed the data about points." << endl;
			break;
		case 3:
			fout << "The user viewed the equation." << endl;
			break;
		case 4:
			fout << "User calculate the equation." << endl;
			break;
		case 0:
			fout << "User logged out" << endl;
			break;
		default:
			fout << "User logged out" << endl;
			break;
		}
	}
	else cout << "File open error" << endl;
	fout.close();
}
