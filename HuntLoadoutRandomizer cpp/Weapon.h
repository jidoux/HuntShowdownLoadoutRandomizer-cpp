#pragma once
#include <iostream>
#include <vector>

class Weapon
{
private:
	std::string name;
	std::string size;
	bool goodLongRange;
	bool goodCloseRange;
	bool hasLevering;
	bool hasFanning;

public:
	Weapon() {
		name = "Unknown";
		size = "Unknown";
		goodLongRange = false;
		goodCloseRange = false;
		hasLevering = false;
		hasFanning = false;
	}
	Weapon(std::string name, std::string size, bool goodLongRange, bool goodCloseRange, bool hasLevering, bool hasFanning) {
		this->name = name;
		this->size = size;
		this->goodLongRange = goodLongRange;
		this->goodCloseRange = goodCloseRange;
		this->hasLevering = hasLevering;
		this->hasFanning = hasFanning;
	}

	void printWeaponData(); // Purely for testing purposes; it prints the weapon data of any Weapon object.

	// 6 getters, notably we have no setters because we have no need to change weapon data, everything is initially set correctly in the list of weapons file.
	std::string getName() const {
		return name;
	}
	std::string getSize() const {
		return size;
	}
	bool getLongRange() const {
		return goodLongRange;
	}
	bool getCloseRange() const {
		return goodCloseRange;
	}
	bool getLevering() const {
		return hasLevering;
	}
	bool getFanning() const {
		return hasFanning;
	}
};
