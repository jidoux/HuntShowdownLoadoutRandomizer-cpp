#include "UsefulTools.h"

std::vector<Weapon> UsefulTools::readFile() {
	std::ifstream infile;
	std::string line;
	std::string name;
	std::string size;
	bool goodCloseRange;
	bool goodLongRange;
	bool hasLevering;
	bool hasFanning;
	std::vector<Weapon> listOfWeapons;

	infile.open("ListOfHuntShowdownWeapons.yml");
	if (!infile.is_open()) {
		std::cout << "Error with opening the list of weapons file, likely due to it not existing or being renamed. Exiting...";
		exit(1);
	}
	while (infile.peek() != EOF) {
		getline(infile, line);
		while (line[0] == '#' && infile.peek() != EOF) { // checks if the starting character for the line is a comment, or if we are at the end of the file
			getline(infile, line);
		}
		if (infile.peek() == EOF) { // ending the file reading (im sure I could've done this better but it works)
			break;
		}
		// the current line is the name attribute
		if (!line.empty()) {
			line.pop_back();
			line.pop_back(); // removes last 2 characters from the line, which in this case should always be a space and {
		}
		name = removeCommentsFromLine(line);
		name = trim(name);
		getline(infile, line); // getting the size attribute
		if (!line.empty()) {
			line.erase(0, 6); // Index position from which we want to delete 0, and second parameter is num characters we want to delete. Function raises exception if string is empty.
		}
		size = removeCommentsFromLine(line);
		size = toLower(trim(size));
		getline(infile, line); // getting the goodLongRange attribute
		if (!line.empty()) {
			line.erase(0, 15);
		}
		if (toLower(trim(line)) == "yes") {
			goodLongRange = true;
		}
		else {
			goodLongRange = false;
		}
		getline(infile, line); // getting the goodCloseRange attribute
		if (!line.empty()) {
			line.erase(0, 18);
		}
		if (toLower(trim(line)) == "yes") {
			goodCloseRange = true;
		}
		else {
			goodCloseRange = false;
		}
		getline(infile, line); // getting the hasLevering attribute
		if (!line.empty()) {
			line.erase(0, 10);
		}
		if (toLower(trim(line)) == "yes") {
			hasLevering = true;
		}
		else {
			hasLevering = false;
		}
		getline(infile, line); // getting the hasFanning attribute
		if (!line.empty()) {
			line.erase(0, 9);
		}
		if (toLower(trim(line)) == "yes") {
			hasFanning = true;
		}
		else {
			hasFanning = false;
		}
		getline(infile, line); // dont need to print this line or anything, its just the ending } for each weapon.
		Weapon myWeapon = Weapon(name, size, goodLongRange, goodCloseRange, hasLevering, hasFanning); // TODO determine if we need getters and setters since we're initializing this 200 times
		listOfWeapons.push_back(myWeapon);
	}
	infile.close();
	return listOfWeapons;
}

void UsefulTools::printWeaponList(std::vector<Weapon> listOfWeapons) {
	std::cout << "The number of weapons is " << listOfWeapons.size() << "\n";
	int count = 0;
	for (int i = 0; i < listOfWeapons.size(); i++) {
		std::cout << listOfWeapons[i].getName() << "\n";
		count++;
	}
	std::cout << "Count is " << count << "\n";
}

std::string UsefulTools::removeCommentsFromLine(std::string line) {
	int index;
	index = line.find('#');
	// its index-3 to get rid of the # and the assummed space before the #. If its not formmated exactly this way there can/will be minor bugs. Idk why its 3 and not 2 tbh.
	// probably not implemented in the smartest way
	return line.substr(0, index - 3);
}

std::string UsefulTools::toLower(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}
	return input;
}

std::string& UsefulTools::trim(std::string& input) {
	input.erase(input.find_last_not_of(' ') + 1); //trimming suffixing spaces
	input.erase(0, input.find_first_not_of(' ')); //trimming prefixing spaces
	return input;
}

bool UsefulTools::determineIfQuartermaster() {
	std::cout << "Do you have the Quartermaster trait? (Please enter only \"Yes\" or \"No\"): ";
	std::string hasQuartermaster = "";
	try {
		std::cin >> hasQuartermaster;
	}
	catch (...) {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
	}
	hasQuartermaster = toLower(trim(hasQuartermaster));
	while (hasQuartermaster != "no" && hasQuartermaster != "yes" && hasQuartermaster != "n" && hasQuartermaster != "y") {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\". \nDo you have the Quartermaster trait? ";
		try
		{
			std::cin >> hasQuartermaster;

		}
		catch (...)
		{
			std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
		}
		hasQuartermaster = toLower(trim(hasQuartermaster));
	}
	if (hasQuartermaster == "y" || hasQuartermaster == "yes") {
		return true;
	}
	else {
		return false;
	}
}

bool UsefulTools::determineIfLevering() {
	std::cout << "Do you have the Levering trait? (Please enter only \"Yes\" or \"No\"): ";
	std::string hasLevering = "";
	try {
		std::cin >> hasLevering;
	}
	catch (...) {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
	}
	hasLevering = toLower(trim(hasLevering));
	while (hasLevering != "no" && hasLevering != "yes" && hasLevering != "n" && hasLevering != "y") {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\". \nDo you have the Levering trait? ";
		try
		{
			std::cin >> hasLevering;

		}
		catch (...)
		{
			std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
		}
		hasLevering = toLower(trim(hasLevering));
	}
	if ((toLower(trim(hasLevering)) == "y") || (toLower(trim(hasLevering)) == "yes")) {
		return true;
	}
	else {
		return false;
	}
}

bool UsefulTools::determineIfFanning() {
	std::cout << "Do you have the Fanning trait? (Please enter only \"Yes\" or \"No\"): ";
	std::string hasFanning = "";
	try {
		std::cin >> hasFanning;
	}
	catch (...) {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
	}
	hasFanning = toLower(trim(hasFanning));
	while (hasFanning != "no" && hasFanning != "yes" && hasFanning != "n" && hasFanning != "y") {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\". \nDo you have the Fanning trait? ";
		try
		{
			std::cin >> hasFanning;

		}
		catch (...)
		{
			std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
		}
		hasFanning = toLower(trim(hasFanning));
	}
	if (hasFanning == "y" || hasFanning == "yes") {
		return true;
	}
	else {
		return false;
	}
}

bool UsefulTools::determineIfUserWantsAnotherLoadout() {
	std::string input;
	std::cout << "Do you want another loadout? Please enter only \"Yes\" or \"No\": ";
	try {
		std::cin >> input;
	}
	catch (...) {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\".\n";
	}
	input = toLower(trim(input));
	while (input != "no" && input != "yes" && input != "y" && input != "n") {
		std::cout << "Invalid input! Please only enter \"Yes\" or \"No\". \nDo you want to generate another random loadout? ";
		try {
			std::cin >> input;
		}
		catch (...) {
			std::cout << "Invalid input! Please only enter \"Yes\" or \"No\"\n";
		}
		input = toLower(trim(input));
	}
	if (input == "yes" || input == "y") {
		return true;
	}
	else {
		return false;
	}
}