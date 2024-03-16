#include "Loadout.h"

void Loadout::generateRandomLoadout(std::vector<Weapon> listOfWeapons, bool hasQuartermaster, bool hasLevering, bool hasFanning, Weapon& weapon1, Weapon& weapon2) {
	int randomNumber = 0;
	bool loadoutDetermined = false;
	while (!loadoutDetermined) {
		randomNumber = Loadout::getRandomNumber(listOfWeapons.size());
		weapon1 = listOfWeapons[randomNumber];
		randomNumber = Loadout::getRandomNumber(listOfWeapons.size());
		weapon2 = listOfWeapons[randomNumber];
        // these checks check for every impossible loadout scenario, else it knows the loadout has been determined
        // these 3 checks are to ensure the weapons are valid sizes (quartermaster checks)
        if (weapon1.getSize() == "large" && weapon2.getSize() == "large") {
            loadoutDetermined = false;
        }
        else if (!hasQuartermaster && weapon1.getSize() == "large" && weapon2.getSize() == "medium") {
            loadoutDetermined = false;
        }
        else if (!hasQuartermaster && weapon1.getSize() == "medium" && weapon2.getSize() == "large") {
            loadoutDetermined = false;
        }
        // these checks are for valid ranged loadouts, checking if these are both false to determine if a loadout isnt viable at a certain range
        else if (!weapon1.getCloseRange() && !weapon2.getCloseRange()) {
            loadoutDetermined = false;
        }
        else if (!weapon1.getLongRange() && !weapon2.getLongRange()) {
            loadoutDetermined = false;
        }
        // if a weapon has fanning and any weapons have long range, everything is covered. Same with levering. So this checks if any weapon has long range. These 4 check for that
        else if (hasFanning && weapon1.getFanning() && (weapon2.getLongRange() || weapon1.getLongRange())) {
            loadoutDetermined = true;
        }
        else if (hasFanning && weapon2.getFanning() && (weapon1.getLongRange() || weapon2.getLongRange())) {
            loadoutDetermined = true;
        }
        else if (hasLevering && weapon1.getLevering() && (weapon2.getLongRange() || weapon1.getLongRange())) {
            loadoutDetermined = true;
        }
        else if (hasLevering && weapon2.getLevering() && (weapon1.getLongRange() || weapon2.getLongRange())) {
            loadoutDetermined = true;
        }
        else {
            loadoutDetermined = true;
        }
	}
}

int Loadout::getRandomNumber(int weaponCount) {
	int randomNum = rand() % weaponCount;
	return randomNum;
}