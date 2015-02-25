#include <iostream>
#include <string>
#include <math.h>
#include "Robot.h"

using namespace std;

int Robot::getDamage() {
	int total_damage = strength + bonus_damage;
	bonus_damage = 0;
	return total_damage;
}
void Robot::reset() {
	Fighter::reset();
	current_energy = max_energy;
	bonus_damage = 0;
}
bool Robot::useAbility() {
	//Shockwave Punch
	if (current_energy >= ROBOT_ABILITY_COST) {
		bonus_damage = strength * pow(current_energy / max_energy, 4);
		current_energy -= ROBOT_ABILITY_COST;
		return true;
	}
	else {
		return false;
	}
	
}