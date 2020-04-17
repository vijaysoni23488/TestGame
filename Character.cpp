/*****************************************
* Filename : Character.cpp
* Creator : Soni, Vijay
* Date : 2018-04-13
*****************************************/

#include "Character.h"
#include <windows.h>

Character::Character(int health, int attackPower, unsigned int attackTimer, std::string name) : _nHealth(health), _nAttackPower(attackPower), _unAttackTimer(attackTimer), _sName(name)
{
	std::cout << _sName << " character created with health " << _nHealth << " , attack power " << _nAttackPower << " , attack time " << _unAttackTimer << "\n";
}

Character::~Character()
{
	std::cout << _sName << " character destroyed! \n";
}

void Character::toAttack(Character* target, int attackPower)
{
	int nTargetHealth = target->getHealth();
	if (_nHealth == 0 || nTargetHealth == 0)
	{
		// Character cannot attack or cannot be attacked
		return;
	}
	else
	{
		Sleep(_unAttackTimer);
		if (attackPower != 0)
			nTargetHealth -= attackPower;
		else
			nTargetHealth -= _nAttackPower;
		
		if (nTargetHealth < 0)
			nTargetHealth = 0;

		std::cout << _sName << " hits " << target->getName() << ", ";
		target->setHealth(nTargetHealth);
		target->checkHealth();
	}
}

int Character::getHealth()
{
	return _nHealth;
}

std::string Character::getName()
{
	return _sName;
}

unsigned int Character::getAttackTimer()
{
	return _unAttackTimer;
}

void Character::setHealth(int health)
{
	_nHealth =  health;
}

void Character::checkHealth()
{
	if (_nHealth > 0)
	{
		std::cout << _sName << " health is " << _nHealth << "! \n";
	} 
	else if (_nHealth == 0 && _sName != "Hero")
	{
		std::cout << _sName << " is dead. \n";
	}
}