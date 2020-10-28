#include "Lab_one.h"

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::Date(Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}


void Date::setDate(int d, int m, int y)
{
	bool check = true;
	do
	{
		if (!check)
		{
			cout << "Incorrect date format. Please, reenter through a space "; cin >> day >> month >> year;
		}
		day = d;
		month = m;
		year = y;
		check = checkDate(day, month, year);
	} while (!(checkDate(day, month, year)));
}
	

void Date::getDate(int* d, int* m, int* y) const
{
	*d = day;
	*m = month;
	*y = year;
}

void Date::write()
{
	ofstream fout;
	fout.open(filename, ios::app);
	if(fout.is_open())
	{
		fout << day << month << year;
	}
	fout.close();
}

void Employee::setSmth()
{
	int code = 0, day, month, year;
	cout << "Enter id : "; cin >> id;
	cout << "Enter salary : "; cin >> salary;
	cout << "Enter place of employee.\n 1 - manager.\n2 - secretary.\n 3 - employee. " << endl;
	cout << "Your choice : "; cin >> code;
	
	switch (code)
	{
	case 1:
		place = manager;
		break;
	case 2:
		place = secretary;
		break;
	case 3:
		place = employee;
	default:
		place = employee;
	}
	cout << "Enter enrollment date trough a space (The format is DD MM YY) : "; cin >> day >> month >> year;
	date.setDate(day, month, year);
	

}

void Employee::getSmth() const
{
	cout << "ID : " << id << endl;
	cout << "Salary : " << salary << endl;
	cout << "Enrollment date : "; date.printDate();
	switch (place)
	{
	case manager:
		cout << "Place : Manager"<<endl;
		break;
	case secretary:
		cout << "Place : Secretary" << endl;
		break;
	case employee:
		cout << "Place : Employee" << endl;
		break;
	}
}

void Date::printDate() const
{
	cout << day << "/" << month << "/" << year << endl;
}

Employee::Employee(Employee& other)
{
	this->id = other.id;
	this->date = other.date;
	this->place = other.place;
	this->salary = other.salary;
}


void Employee::writeToFile()
{
	ofstream fout;
	fout.open(filename, ios::app);
	if(fout.is_open())
	{
		fout << id << salary << place;
		date.write();
	}
	fout.close();
}

bool checkDate(int d, int m, int y)
{
	bool checkMonth = false;
	bool bissextile = false;

	if (!(y % 4)) bissextile = true;

	if (m > 0 && m <= 12)
	{
		switch (m)
		{
		case 4:
			checkMonth = true;
			break;
		case 6:
			checkMonth = true;
			break;
		case 9:
			checkMonth = true;
			break;
		case 11:
			checkMonth = true;
			break;
		}
	}
	else return false;
	if (m == 2)
	{
		if (!(bissextile && d >= 0 && d <= 29))return false;
		else if (!(d > 0 && d <= 28)) return false;
	}

	if (checkMonth)
	{
		if (!(d > 0 && d < 30)) return false;
	}
	else if (!(d > 0 && d < 31)) return false;

	return true;
}
