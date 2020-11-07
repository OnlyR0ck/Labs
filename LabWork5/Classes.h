#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

class Power
{
protected:
	string type;
	int capacity;
public:
	string getType();
	void setType();
	int getCapacity();
	void setCapacity();
	Power();
	Power(string, int);
};

class Display
{
protected:
	string type;
	bool requirePower;
public:
	Display();
	Display(string, bool);
	string getType();
	void setType();
	bool getRequirePower();
	void setRequirePower();
};

class Watch
{
protected:
	string developer;
	double price;
public:
	Display display;
	Power power;
	Watch();
	Watch(string, string, int, bool, string, double);
	string getDev();
	void setDev();
	double getPrice();
	void setPrice();
	virtual void showTime() = 0;
};


class SmartWatch : public Watch
{
private:
	int calories;
	int heartbeat;
public:
	SmartWatch();
	SmartWatch(string, string, int, bool, string, double, int, int);
	SmartWatch(SmartWatch&);
	int getCalories();
	void setCalories();
	int getHearbeat();
	void setHearbeat();
	void showTime() override;
};

class MechanicalWatch : public Watch
{
private:
	string clockFormat;
	int mainspring;
public:
	MechanicalWatch();
	MechanicalWatch(string, string, int, bool, string, double, string, int);
	MechanicalWatch(MechanicalWatch&);
	string getClockFormat();
	void setClockFormat();
	int getMainspring();
	void setMainspring();
	void showTime() override;
};
