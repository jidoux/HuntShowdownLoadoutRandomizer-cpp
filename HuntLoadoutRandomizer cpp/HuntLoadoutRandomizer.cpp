#include <iostream>
#include <vector>
#include "Weapon.h"
#include "UsefulTools.h"
#include "Loadout.h"

int main() {
	srand((unsigned) time(NULL)); // seeding the random number generator in Loadout.cpp 
	std::vector<Weapon> listOfWeapons = UsefulTools::readFile();

	std::cout << "Welcome to the Hunt Showdown loadout randomizer!\n";
	bool hasQuartermaster = UsefulTools::determineIfQuartermaster();
	bool hasLevering = UsefulTools::determineIfLevering();
	bool hasFanning = UsefulTools::determineIfFanning();

	bool giveLoadouts = true;

	Weapon weapon1 = Weapon(); // could also do a loadout struct or smth in Loadout file which may be better than passing these by reference to update them
	Weapon weapon2 = Weapon();
	while (giveLoadouts) {
		Loadout::generateRandomLoadout(listOfWeapons, hasQuartermaster, hasLevering, hasFanning, weapon1, weapon2);
		std::cout << "\nYour loadout is " << weapon1.getName() << " and " << weapon2.getName() << "!\n";
		giveLoadouts = UsefulTools::determineIfUserWantsAnotherLoadout();
	}
}