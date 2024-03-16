#include "Weapon.h"

void Weapon::printWeaponData() {
	std::cout << "Weapon name is: " << getName() << "\n";
	std::cout << "Weapon size is: " << getSize() << "\n";
}