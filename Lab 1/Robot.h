#pragma once

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

class Robot : public Fighter {
private:
	double current_energy;
	double max_energy;
	int bonus_damage;
public:
	Robot(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) :Fighter(name_in, hp_in, strength_in, speed_in, magic_in){
		this->max_energy = 2 * magic;
		this->current_energy = max_energy;
		this->bonus_damage = 0;
	};
	int getDamage();
	void reset();
	bool useAbility();
};