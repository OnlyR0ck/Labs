#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace  std;

const string filename = "Employee.bin";

void checkDate();


enum Etype
{
	manager = 1,
	secretary,
	employee
};
struct structDate
{
	int day;
	int month;
	int year;
};
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() : day(0), month(0), year(0) {};
	Date(int, int, int);
	Date(Date& other);
	void printDate() const;
	void setDate(int, int, int);
	void getDate(int*, int*, int*) const;
	void write();
	
};

class Employee
{
private:
	int id;
	float salary;
	Date date;
	Etype place;
	
public:
	Employee() : id(0), salary(0), date(0, 0, 0), place() {};
	Employee(Employee& other);
	void setSmth();
	void getSmth() const;
	void writeToFile();
	friend ostream& operator<<(ostream& out, Employee& obj);
};

bool checkDate(int, int, int);
