//// HelperLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
#include "HelperLib.h"

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void Menu(delegate arr[], int size, string arr_names[])
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	const char* top =
		R"(
 ███▄ ▄███▓▓█████  ███▄    █  █    ██
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █  ██  ▓██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▓██  ▒██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒▓▓█  ░██░
▒██▒   ░██▒░▒████▒▒██░   ▓██░▒▒█████▓
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░░░▒░ ░ ░ 
░      ░      ░      ░   ░ ░  ░░░ ░ ░ 
       ░      ░  ░         ░    ░    )";
	int* Set = new int[size];
	set_color(Set, size, 7);
	int counter = 0;
	char key;
	while (true)
	{
		gotoXY(0, 0);
		color(4);
		cout << top << endl;
		for (int j = 0; j < size; j++)
		{
			gotoXY(1, 12 + j);
			color(Set[j]);
			cout << j + 1 << ". " << arr_names[j] << endl;
		}

		key = _getch();
		if (static_cast<int>(key) == -32)
		{
			switch (static_cast<int>(_getch()))
			{
			case 72:
				if ((counter >= 1 && counter < size))
				{
					counter--;
				}
				break;
			case 80:
				if (counter >= 0 && counter < size - 1)
				{
					counter++;
				}
				break;
			}
		}
		else if (key == '\r')
		{
			if (counter == size - 1)exit(0);
			system("cls");
			arr[counter]();
			_getch();
			system("cls");
		}

		set_color(Set, size, 7);

		if (counter >= 0 && counter < size)
		{
			Set[counter] = 4;
		}
	}
}

void set_color(int* arr, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = color;
	}
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