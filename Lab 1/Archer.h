#pragma once

#include <iostream>
#include <string>
#include "Header.h"

class Archer : public Fighter {
private:
	int current_speed;
public:
	Archer(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) :Fighter(name_in, hp_in, strength_in, speed_in, magic_in){
		this->current_speed = speed;
	};
	int getSpeed();
	int getDamage();
	void reset();
	bool useAbility();
};