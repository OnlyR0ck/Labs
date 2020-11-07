#include "Classes.h"
#include "HelperLib.h"

namespace LabWork5
{
	SmartWatch sWatch;
	MechanicalWatch mWatch;
	void setParams();
	void showParams();
	void showTime();
	void writeToFile();

	void setParams()
	{
		cout << "Enter info about smart watch: " << endl;
		sWatch.setDev();
		sWatch.setPrice();
		sWatch.setCalories();
		sWatch.setHearbeat();
		sWatch.display.setRequirePower();
		sWatch.display.setType();
		sWatch.power.setType();
		sWatch.power.setCapacity();

		cout << "\nEnter info about mechanical watch: " << endl;
		mWatch.setDev();
		mWatch.setPrice();
		mWatch.setClockFormat();
		mWatch.setMainspring();
		mWatch.display.setRequirePower();
		mWatch.display.setType();
		mWatch.power.setType();
		mWatch.power.setCapacity();

		cout << "The end" << endl;
	}

	void showParams()
	{
		cout << "Info about smart watch: " << endl;
		cout << "Dev: " << sWatch.getDev() << endl;
		cout << "Price: " << sWatch.getPrice() << endl;
		cout << "Calories: " << sWatch.getCalories() << endl;
		cout << "Heartbeat: " << sWatch.getHearbeat() << endl;
		cout << "Require power: " << sWatch.display.getRequirePower() << endl;
		cout << "Display type: " << sWatch.display.getType() << endl;
		cout << "Power type:" << sWatch.power.getType() << endl;
		cout << "Capacity: " << sWatch.power.getCapacity() << endl;

		cout << "\nInfo about mechanical watch: " << endl;
		cout << "Dev: " << mWatch.getDev() << endl;
		cout << "Price: " << mWatch.getPrice() << endl;
		cout << "Clock format: " << mWatch.getClockFormat() << endl;
		cout << "Tense of mainspring: " << mWatch.getMainspring() << endl;
		cout << "Require power: " << mWatch.display.getRequirePower() << endl;
		cout << "Display type: " << mWatch.display.getType() << endl;
		cout << "Power type:" << mWatch.power.getType() << endl;
		cout << "Capacity: " << mWatch.power.getCapacity() << endl;

		cout << "The end" << endl;
	}

	void showTime()
	{
		cout << "Current date and time and other info: " << endl;
		sWatch.showTime();

		cout << "\nCurrent time:";
		mWatch.showTime();
	}

	void writeToFile()
	{
		ofstream fout;
		fout.open("WatchInfo", ios::app);
		if (fout.is_open())
		{
			fout << "Info about smart watch: " << endl;
			fout << "Dev: " << sWatch.getDev() << endl;
			fout << "Price: " << sWatch.getPrice() << endl;
			fout << "Calories: " << sWatch.getCalories() << endl;
			fout << "Heartbeat: " << sWatch.getHearbeat() << endl;
			fout << "Require power: " << sWatch.display.getRequirePower() << endl;
			fout << "Display type: " << sWatch.display.getType() << endl;
			fout << "Power type:" << sWatch.power.getType() << endl;
			fout << "Capacity: " << sWatch.power.getCapacity() << endl;

			fout << "Info about mechanical watch: " << endl;
			fout << "Dev: " << mWatch.getDev() << endl;
			fout << "Price: " << mWatch.getPrice() << endl;
			fout << "Clock format: " << mWatch.getClockFormat() << endl;
			fout << "Tense of mainspring: " << mWatch.getMainspring() << endl;
			fout << "Require power: " << mWatch.display.getRequirePower() << endl;
			fout << "Display type: " << mWatch.display.getType() << endl;
			fout << "Power type:" << mWatch.power.getType() << endl;
			fout << "Capacity: " << mWatch.power.getCapacity() << endl;
		}
		fout.close();
	}
}

int main()
{
	delegate* delegateArr = new delegate[5];
	delegateArr[0] = LabWork5::setParams;
	delegateArr[1] = LabWork5::showParams;
	delegateArr[2] = LabWork5::showTime;
	delegateArr[3] = LabWork5::writeToFile;
	auto names = new string[5];
	names[0] = "Set up clocks info";
	names[1] = "Show clocks info";
	names[2] = "Show time";
	names[3] = "Write info to file";
	names[4] = "Exit";
	Menu(delegateArr, 5, names);
	return 0;
}