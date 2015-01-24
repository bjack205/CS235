#pragma once

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

class Robot : public Fighter {
public:
	Robot(string name_in, int hp_in, int strength_in, int speed_in, int magic_in) :Fighter(name_in, hp_in, strength_in, speed_in, magic_in){};
	int getDamage();
	void takeDamage(int damage);
	void reset();
	bool useAbility();
};