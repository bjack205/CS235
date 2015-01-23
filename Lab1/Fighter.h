#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "FighterInterface.h"

using std::cout;
using std::string;

class Fighter : public FighterInterface {
private:
	string name;
	int maxHP;
	int currentHP;
	int strength;
	int speed;
	int magic;

public:
	Fighter(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) : name(name_in), maxHP(hp_in), currentHP(hp_in), strength(strength_in), speed(speed_in), magic(magic_in) {};
	Fighter(){};

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();

};
