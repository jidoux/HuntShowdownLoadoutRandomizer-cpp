#pragma once
#include <iostream>
#include <vector>
#include "Weapon.h"
class Loadout
{
public:
	static void generateRandomLoadout(std::vector<Weapon> listOfWeapons, bool hasQuartermaster, bool hasLevering, bool hasFanning, Weapon& weapon1, Weapon& weapon2);
	static int getRandomNumber(int weaponCount);
};

