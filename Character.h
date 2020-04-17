/*****************************************
* Filename : Character.h
* Creator : Soni, Vijay
* Date : 2018-04-13
*****************************************/
#pragma once

#include <iostream>

class Character
{
public:
	Character(int health, int attackPower, unsigned int attackTimer, std::string name);
	virtual ~Character();

	void toAttack(Character* target, int attackPower = 0);

	int getHealth();
	std::string getName();
	void setHealth(int health);
	unsigned int getAttackTimer();
	void checkHealth();

private:
	int _nHealth;
	int _nAttackPower;
	unsigned int _unAttackTimer;
	std::string _sName;
};