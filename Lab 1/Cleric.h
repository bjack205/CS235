#pragma once

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

class Cleric : public Fighter {
private:
	int mana;
	int mana_max;
public:
	Cleric(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) :Fighter(name_in, hp_in, strength_in, speed_in, magic_in){
		this->mana_max = magic * 5;
		this->mana = mana_max;
	};
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};