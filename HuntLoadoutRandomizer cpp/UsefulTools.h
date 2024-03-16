#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>
#include "Weapon.h"

class UsefulTools
{
public:
	static std::vector<Weapon> readFile();
	static void printWeaponList(std::vector<Weapon> listOfWeapons);
	static std::string removeCommentsFromLine(std::string line);
	static std::string toLower(std::string input);
	static std::string& trim(std::string& input);
	static bool determineIfQuartermaster(); // TODO merge these 3 functions into 1
	static bool determineIfLevering();
	static bool determineIfFanning();
	static bool determineIfUserWantsAnotherLoadout();
};

