#pragma once

#include <iostream>
#include <string>
#include "Header.h"

class Archer : public Fighter {
private:
	int current_speed;
public:
	int getSpeed();
	int getDamage();
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();
};