#pragma once

#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

typedef void (*delegate)();
void Menu(delegate[] , int, string[]);
void set_color(int*, int, int);
void gotoXY(int, int);
void color(int);
void set_color(int*, int, int);
int correct_user_input();