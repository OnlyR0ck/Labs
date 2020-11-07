#include "Classes.h"

string Power::getType()
{
	return type;
}

void Power::setType()
{
	cout << "Enter type of power: ";
	cin >> type;
}

int Power::getCapacity()
{
	return capacity;
}

void Power::setCapacity()
{
	cout << "Enter capacity: ";
	cin >> capacity;
}

Power::Power() : type("N/A"), capacity(0)
{
}

Power::Power(string type, int capacity)
{
	this->type = type;
	this->capacity = capacity;
}

Display::Display() : type("N/A"), requirePower(false)
{
}

Display::Display(string type, bool rPower)
{
	this->type = type;
	this->requirePower = rPower;
}

string Display::getType()
{
	return type;
}

void Display::setType()
{
	cout << "Enter type of display tech: ";
	cin >> type;
}

bool Display::getRequirePower()
{
	return requirePower;
}

void Display::setRequirePower()
{
	cout << "If device req power, enter 1, else 0 : ";
	cin >> requirePower;
}

Watch::Watch()
{
	this->display = Display();
	this->power = Power();
	this->developer = "N/A";
	this->price = 0;
}

Watch::Watch(string dType, string pType, int capacity, bool rPower, string dev, double pr)
{
	this->display = Display(dType, rPower);
	this->power = Power(pType, rPower);
	this->developer = dev;
	this->price = pr;
}

string Watch::getDev()
{
	return developer;
}

void Watch::setDev()
{
	cout << "Enter dev company name: ";
	cin >> developer;
}

double Watch::getPrice()
{
	return price;
}

void Watch::setPrice()
{
	cout << "Enter price of watch: ";
	cin >> price;
}

SmartWatch::SmartWatch() : Watch()
{
	calories = 0;
	heartbeat = 0;
}

SmartWatch::SmartWatch(string dType, string pType, int capacity, bool rPower, string dev, double pr, int cal,
                       int hb) : Watch(dType, pType, capacity, rPower, dev, pr)
{
	this->calories = cal;
	this->heartbeat = hb;
}

SmartWatch::SmartWatch(SmartWatch& other)
{
	this->calories = other.calories;
	this->heartbeat = other.heartbeat;
}

int SmartWatch::getCalories()
{
	return calories;
}

void SmartWatch::setCalories()
{
	cout << "Enter spend calories: ";
	cin >> calories;
}

int SmartWatch::getHearbeat()
{
	return heartbeat;
}

void SmartWatch::setHearbeat()
{
	cout << "Enter your heartbeat: ";
	cin >> heartbeat;
}

void SmartWatch::showTime()
{
	time_t t = time(nullptr); // get time now
	tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
	cout << now->tm_hour << ":" << now->tm_min << endl;
	cout << "Spent calories: " << this->calories << endl;
	cout << "Your heartbeat: " << this->heartbeat << endl;
}

MechanicalWatch::MechanicalWatch() : Watch()
{
	clockFormat = "N/A";
	mainspring = 0;
}

MechanicalWatch::MechanicalWatch(string dType, string pType, int capacity, bool rPower, string dev, double pr,
                                 string cF, int mS) : Watch(dType, pType, capacity, rPower, dev, pr)
{
	this->clockFormat = cF;
	this->mainspring = mS;
}

MechanicalWatch::MechanicalWatch(MechanicalWatch& other)
{
	this->clockFormat = other.clockFormat;
	this->mainspring = other.mainspring;
}

string MechanicalWatch::getClockFormat()
{
	return clockFormat;
}

void MechanicalWatch::setClockFormat()
{
	cout << "Enter clock format: ";
	cin >> clockFormat;
}

int MechanicalWatch::getMainspring()
{
	return mainspring;
}

void MechanicalWatch::setMainspring()
{
	cout << "Enter tension of mainspring: ";
	cin >> mainspring;
}

void MechanicalWatch::showTime()
{
	time_t t = time(nullptr); // get time now
	tm* now = localtime(&t);
	cout << now->tm_hour << ":" << now->tm_min << endl;
}
