/*
 * Fighter.h
 *
 *  Created on: Jan 15, 2015
 *      Author: bjack205
 */

#pragma once

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;

class Fighter {
private:
	string name;
	int hp;
	int magic;

public:
	Fighter(string name_in, int hp_in, int strength_in, int magic_in) : name(name_in), hp(hp_in), magic(magic_in) {};
	Fighter();

	string getName() {
		return name;
	}
	int getHP() {
		return hp;
	}
	int getMagic() {
		return magic;
	}
};
