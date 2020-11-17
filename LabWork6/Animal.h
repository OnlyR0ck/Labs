#pragma once
#include <string>
#include <iostream>
#include "HelperLib.h"

using namespace std;

class Animal
{
protected:
	bool isHungry;
	int health;
public:
	Animal() : isHungry(true), health(0) {}
	bool getIsHungry();
	void setIsHungry();
	int getHealth();
	void setHealth();
	virtual void Move();
};

class Cat : virtual private Animal
{
protected:
	string name;
	int mood;
public:
	Cat() : Animal(), name("N/A"), mood(0) {}
	string getName();
	void setName(); // name and animal params;
	int getMood();
	void setMood();
	void setOtherParams();
	void getOtherParams();
	void Move() override;
};

class Dog : virtual public Animal
{
protected:
	string nickName;
	bool requireStroll;
public:
	Dog() : Animal(), nickName("N/A"), requireStroll(false) {};
	string getNickName();
	void setNickName();
	bool getRequireStroll();
	void setRequireStroll();
	void setOtherParams();
	void getOtherParams();
	void Move() override;
};

class Human
{
private:
	int height;
	string name;
public:
	Human() : height(0), name("N/A") {}
	void virtual Speak();
	int getHeight();
	void setHeight();
	string getName();
	void setName();
};

class CatDog : public Cat, public Dog, protected Human
{
protected:
	string color;
	bool isAwake;
public:
	CatDog() : Cat(), Dog(), color("N/A"), isAwake(false) {}
	string getColor();
	void setColor();
	bool getIsAwake();
	void setIsAwake();
	void Move() override;
	void Speak() override;
	
};