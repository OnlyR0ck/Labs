#include "Animal.h"

namespace LabWork6
{
	Animal animal;
	Cat cat;
	Dog dog;
	Human human;
	CatDog catdog;

	void EnterData()
	{
		int code = 1;
		while(code)
		{
			cout << "1 - Enter info about animal\n2 - Enter info about cat\n3 - Enter info about dog\n4 - Enter info about CatDog\n5 - Enter info about hu-man\n0 - Back" << endl;
			cout << "Code : "; cin >> code;
			switch (code)
			{
			case 1 :
				animal.setHealth();
				animal.setIsHungry();
				break;
			case 2:
				cat.setName();
				cat.setMood();
				cat.setOtherParams();
				break;
			case 3:
				dog.setNickName();
				dog.setRequireStroll();
				dog.setOtherParams();
				break;
			case 4:
				catdog.setColor();
				catdog.setIsAwake();
				break;
			case 5:
				human.setName();
				human.setHeight();
			default:
				code = 0;
			}
			system("cls");
		}
	}

	void showData()
	{
		int code = 1;
		while (code)
		{
			cout << "1 - Show info about animal\n2 - Show info about cat\n3 - Show info about dog\n4 - Show info about CatDog\n5 - Show info about Hu-man\n0 - Back" << endl;
			cout << "Code : "; cin >> code;
			switch (code)
			{
			case 1:
				cout << "Animal health : " << animal.getHealth() << endl;
				animal.getIsHungry() ? cout << "Animal is hungry\n" : cout << "Animal is full.\n";
				_getch();
				break;
			case 2:
				cout << "Cat name : " << cat.getName() << endl;
				cout << "Cat mood : " << cat.getMood() << endl;
				cat.getOtherParams();
				_getch();
				break;
			case 3:
				cout << "Dog name : " << dog.getNickName() << endl;
				dog.getRequireStroll() ? cout << "Get out with your puppy!\n" : cout << "Just chill out\n";
				dog.getOtherParams();
				_getch();
				break;
			case 4:
				cout << "CatDog color : " << catdog.getColor() << endl;
				catdog.getIsAwake() ? cout << "Hello, honey!\n" : cout << "Cshh, you can wake up him.\n";
				_getch();
				break;
			case 5:
				cout << "Hu-man height : " << human.getHeight() << endl;
				cout << "Hu-man name : " << human.getName() << endl;
				_getch();
				break;
			default:
				code = 0;
			}
			system("cls");
		}
	}
}

int main()
{
	delegate* delegateArr = new delegate[2];
	delegateArr[0] = LabWork6::EnterData;
	delegateArr[1] = LabWork6::showData;
	auto names = new string[3];
	names[0] = "Enter data about objects";
	names[1] = "Show data about objects";
	names[2] = "Exit";
	Menu(delegateArr, 3, names);
	return 0;
}