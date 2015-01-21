
#include <iostream>
#include <string>
#include "Fighter.h"

using namespace std;

string Fighter::getName() {
	return name;
}
int Fighter::getMaximumHP() {
	return maxHP;
}
int Fighter::getCurrentHP() {
	return currentHP;
}
int Fighter::getStrength() {
	return strength;
}
int Fighter::getSpeed() {
	return speed;
}
int Fighter::getMagic() {
	return magic;
}
int Fighter::getDamage() { //Class Specific
	return 0;
}
void Fighter::takeDamage(int damage) {
	int dodge = speed / 4;
	int damage_done = damage - dodge;
	if (damage_done < 1) damage_done = 1;
	currentHP -= damage_done;
}
void Fighter::reset() {
	currentHP = maxHP;
}
void Fighter::regenerate() {
	int heal = strength / 6;
	if (heal < 1) heal = 1;
	if (currentHP + heal > maxHP)
		currentHP = maxHP;
	else
		currentHP += heal;
}
bool Fighter::useAbility() {
	return false;
}

