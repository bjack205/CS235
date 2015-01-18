#pragma once
#ifndef FIGHTER_H
#define FIGHTER_H

using namespace std; 
#include <iostream> 
#include <string>
#include <sstream>
#include "FighterInterface.h"



class Fighter : public FighterInterface
{
protected:
	string name;
	int hp_max;
	int hp_current;
	int strength;
	int speed;
	int magic;

public:
	Fighter(string name_in, int hp_in, int strength_in, int speed_in, int magic_in);
	Fighter();

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	virtual int getSpeed();
	int getMagic();
	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();
	
};






#endif
