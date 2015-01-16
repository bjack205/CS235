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
	Fighter(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) : name(name_in), maxHP(hp_in), speed(speed_in), magic(magic_in) {};
	Fighter(){};

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	int getDamage();
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();

};
