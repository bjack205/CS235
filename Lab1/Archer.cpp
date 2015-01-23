#include <iostream>
#include <string>
#include "Archer.h"

using namespace std;

int Archer::getSpeed() {
	return current_speed;
}
int Archer::getDamage() {
	return 0;
}
void Archer::takeDamage(int damage) {

}
void Archer::reset() {

}
void Archer::regenerate() {

}
bool Archer::useAbility() {
	return false;
}