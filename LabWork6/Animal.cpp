#include "Animal.h"

bool Animal::getIsHungry()
{
	return isHungry;
}

void Animal::setIsHungry()
{
	cout << "Is your Animal Hungry?(Enter 1 for Yes and 0 for No) : ";
	isHungry = correct_user_input();
}

int Animal::getHealth()
{
	return health;
}

void Animal::setHealth()
{
	cout << "Enter health of animal : ";
	health = correct_user_input();
}

void Animal::Move()
{
	cout << "You got yourself moving somehow!" << endl;
}

string Cat::getName()
{
	return name;
}

void Cat::setName()
{
	cout << "Enter name of this pussy cat : ";
	cin >> name;
}

int Cat::getMood()
{
	return mood;
}

void Cat::setMood()
{
	cout << "Enter mood of your pussy cat : ";
	mood = correct_user_input();
}

void Cat::setOtherParams()
{
	Animal::setHealth();
	Animal::setIsHungry();
}

void Cat::getOtherParams()
{
	cout << "The health of animal is " << Animal::getHealth() << endl;
	Animal::getIsHungry() ? cout << "Your animal is hungry.\n" : cout << "Your animal is full.\n";
}

void Cat::Move()
{
	cout << "First leg, second leg and etc." << endl;
}

string Dog::getNickName()
{
	return nickName;
}

void Dog::setNickName()
{
	cout << "Enter nickname of your puppy : ";
	cin >> nickName;
}

bool Dog::getRequireStroll()
{
	return requireStroll;
}

void Dog::setRequireStroll()
{
	cout << "Does your puppy require a stroll?(Enter 1 for Yes and 0 for No) : ";
	requireStroll = correct_user_input();
}

void Dog::setOtherParams()
{
	Animal::setHealth();
	Animal::setIsHungry();
}

void Dog::getOtherParams()
{
	cout << "The health of animal is " << Animal::getHealth() << endl;
	Animal::getIsHungry() ? cout << "Your animal is hungry.\n" : cout << "Your animal is full.\n";
}

void Dog::Move()
{
	cout << "Just wzzuuuh" << endl;
}

void Human::Speak()
{
	cout << "Bluh-bluh-bluh" << endl;
}

int Human::getHeight()
{
	return height;
}

void Human::setHeight()
{
	cout << "Enter height of your hu-man : ";
	height = correct_user_input();
}

string Human::getName()
{
	return name;
}

void Human::setName()
{
	cout << "Enter name of your hu-man : ";
	cin >> name;
}

string CatDog::getColor()
{
	return color;
}

void CatDog::setColor()
{
	Cat::setMood();
	Cat::setOtherParams();
	Cat::setName();
	Dog::setNickName();
	Dog::setRequireStroll();
	cout << "Enter color of your catdog : ";
	cin >> color;
}

bool CatDog::getIsAwake()
{
	return isAwake;
}

void CatDog::setIsAwake()
{
	cout << "Does your catdog still awake?(Enter 1 for Yes and 0 for No) : ";
	isAwake = correct_user_input();
}

void CatDog::Move()
{
	cout << "Hey, Cat, turn right! No, Dog, fck you, we go to the cinema!" << endl;
}

void CatDog::Speak()
{
	cout << "Hello, let's talk about einstein's theory of relativity!" << endl;
}
