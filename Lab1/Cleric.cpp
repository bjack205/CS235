#include <iostream>
#include <string>
#include "Cleric.h"

using namespace std;

int Cleric::getDamage() {
	return magic;
}
void Cleric::reset() {
	mana = mana_max;
}
void Cleric::regenerate() {
	int mana_boot = magic / 5;
	if (mana_boot < 1) mana_boot = 1;
	if (mana + mana_boot > mana_max) {
		mana = mana_max;
	}
	else {
		mana += mana_boot;
	}
}
bool Cleric::useAbility() {
	//Healing Light
	if (mana >= CLERIC_ABILITY_COST) {
		int heal = magic / 3;
		if (heal < 1) heal = 1;
		if (currentHP + heal > maxHP) {
			currentHP = maxHP;
		}
		else {
			currentHP += heal;
		}
		mana -= CLERIC_ABILITY_COST;
		return true;
	}
	else return false;
}