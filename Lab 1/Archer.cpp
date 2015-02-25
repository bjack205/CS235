#include <iostream>
#include <string>
#include "Archer.h"

using namespace std;

int Archer::getSpeed() {
	return current_speed;
}
int Archer::getDamage() {
	return current_speed;
}
void Archer::reset() {
	Fighter::reset();
	current_speed = speed;
}
bool Archer::useAbility() {
	//Quickstep
	current_speed++;
	return true;
}