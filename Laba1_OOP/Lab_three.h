#pragma once
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Set
{
	int size;
	int* arr;
public:
	Set();
	Set(int);
	Set(int, int*);
	Set(vector<int>);
	Set(const Set&);
	void set_set();
	int* get_set();
	Set operator&(const Set&);
	Set operator|(const Set&);
	friend ostream& operator<<(ostream& out, const Set& set);
	friend istream& operator>> (istream& in, Set& set);
	~Set();
};

ostream& operator<< (ostream& out, const Set& set);
istream& operator>> (istream& in, Set& set);
void Menu();
int correct_user_input1();
void remove(vector<int>& v);