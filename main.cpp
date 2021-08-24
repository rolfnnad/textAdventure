#include "main.h"

int difficulty;
int menuChoice;
bool menuRunning = false;
bool gameRunning = false;
int pointBuy = 27;
int statType;
int statChoice;
int raceChoice;
int classChoice;

player playerStats;

races playerRace;

features classFeatures;

armory equipment;

int main()
{

	//run mainmenu
	mainMenu();
	//check if game is running
	if (gameRunning == true)
	{
		//run character creation
		characterCreation();
	}
	//shut down
	else
	{
		cout << "Shutting down..." << endl;
	}


	system("pause");
	return 0;

}

//function displays stats at will
void statsDisplay() {

	//prints stats one line at a time
	cout << endl << endl;
	cout << "STATS" << endl;
	cout << "STR: " << playerStats.getStat(0) << endl;
	cout << "DEX: " << playerStats.getStat(1) << endl;
	cout << "CON: " << playerStats.getStat(2) << endl;
	cout << "INT: " << playerStats.getStat(3) << endl;
	cout << "WIS: " << playerStats.getStat(4) << endl;
	cout << "CHA: " << playerStats.getStat(5) << endl << endl;

	if (classChoice > 0) {
		cout << "CLASS: " << playerStats.get_playerClass() << endl;
		cout << "HITPOINTS: " << playerStats.get_hitPoints() << endl;
		cout << "ARMOR CLASS: " << playerStats.get_armorClass() << "		ARMOR TYPE: " << playerStats.get_playerArmorName() << endl << endl;
	}

}

//ability select function
void abilitySelection() {
	//print instructions
	cout << endl << "You have " << pointBuy << " points to spend on your abilities." << endl;
	cout << "The cost of each score is as follows." << endl;
	cout << "SCORE				COST" << endl;
	cout << "8				0" << endl;
	cout << "9				1" << endl;
	cout << "10				2" << endl;
	cout << "11				3" << endl;
	cout << "12				4" << endl;
	cout << "13				5" << endl;
	cout << "14				7" << endl;
	cout << "15				9" << endl;

	//point allocation only goes so long as the player has more than 0 points to spend
	while (pointBuy > 0) {

		cout << endl << "You have " << pointBuy << " points remaining. How many points would you like to spend on your " << playerStats.get_abilityName(statType) << " ability?" << endl;
		cin >> statChoice;
		//sets appropriate totals for spending of 0-5 points
		if (statChoice <= pointBuy && statChoice <= 5) {
			playerStats.setStat(statType, statChoice);
			pointBuy = pointBuy - statChoice;
			statsDisplay();
			statType++;
		} // sets appropriate totals for spending of 7 points
		else if (statChoice <= pointBuy && statChoice == 7) {
			pointBuy = pointBuy - statChoice;
			statChoice--;
			playerStats.setStat(statType, statChoice);
			statsDisplay();
			statType++;
		} // sets appropriate totals for spending of 9 points
		else if (statChoice <= pointBuy && statChoice == 9) {
			pointBuy = pointBuy - statChoice;
			statChoice -= 2;
			playerStats.setStat(statType, statChoice);
			statsDisplay();
			statType++;
		} //tries again
		else {
			cout << "That is not a valid selection!" << endl;
		}
		// if player didn't spend all their points, they must reallocate
		if (pointBuy > 0 && statType == 6) {
			cout << endl << "You didn't spend all your points! Try again." << endl;
			statType = 0;
			pointBuy = 27;
			statChoice = 0;
			//resets stats
			while (statType < 6) {
				playerStats.resetStats(statType);
				statType++;
			}
			statType = 0;
		}
		else {
		}
	}
}

//race select function
void raceSelection() {
	//prints choose race instructions list
	cout << "Choose your race." << endl << endl;
	cout << "(1) Dwarf (+2 to Constitution)" << endl;
	cout << "(2) Elf (+2 to Dexterity)" << endl;
	cout << "(3) Human (+1 to all)" << endl << endl;
	// menu for choosing race
	while (raceChoice < 1 || raceChoice > 4) {
		cin >> raceChoice;
		switch (raceChoice) {
		case 1:
			playerRace.setDwarf();
			break;
		case 2:
			playerRace.setElf();
			break;
		case 3:
			playerRace.setHuman();
			break;
		default:
			cout << endl << "Error!" << endl << endl;
			break;
		}
	}
}

//class select function
void classSelection() {
	//class selection
	cout << "Choose your class!" << endl;
	cout << "(1) Cleric" << endl;
	cout << "(2) Fighter" << endl;
	cout << "(3) Wizard" << endl;
	while (classChoice < 1 || classChoice > 3) {
		cin >> classChoice;
		switch (classChoice) {
		case 1:
			classFeatures.setCleric(1);
			break;
		case 2:
			classFeatures.setFighter(2);
			break;
		case 3:
			classFeatures.setWizard(3);
			break;
		default:
			cout << "Wrong!" << endl;
			break;
		}
	}
}

//equipment select function
void equipmentSelection() {
	int armorChoice = 0;
	cout << "Choose your armor!" << endl << endl;
	cout << "(1) Leather Armor (11 Armor + Dex Modifier)" << endl;
	cout << "(2) Scale Mail (14 Armor + Dex Modifier to a maximum of 2, disadvantage on stealth)" << endl;
	cout << "(3) Chain Mail (16 Armor with disadvantage on Stealth)" << endl;
	while (armorChoice < 1 || armorChoice > 3) {
		cin >> armorChoice;
		switch (armorChoice) {
		case 1:
		case 2:
		case 3:
			equipment.armorSelect(armorChoice);
			break;
		default :
			cout << "try again dumbo" << endl;
			break;
		}
	}
}

//this function runs the character creation process
void characterCreation()
{
	//runs ability select function
	abilitySelection();
	// displays stats after ability selection
	cout << "You have chosen the following stats." << endl;
	statsDisplay();
	//runs race select function
	raceSelection();
	//displays stats after race selection
	cout << "Your stats have been modified." << endl;
	statsDisplay();
	//runs class select function
	classSelection();
	//displays stats after class selection
	equipmentSelection();
	cout << "Your character is the following." << endl;
	statsDisplay();
}

//this function runs the mainMenu process
int mainMenu()
{

	menuRunning = true;

	while (menuRunning == true)
	{

		menuChoice = 0;
		//displays menu
		cout << "MAIN MENU" << endl;
		cout << "(1) Play" << endl;
		cout << "(2) Difficulty" << endl;
		cout << "(3) Credits" << endl;
		cout << "(4) Exit" << endl;

		cin >> menuChoice;
		//checks if input is a letter
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//menu menu
		if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4)
		{
			switch (menuChoice)
			{
			case 1:
				gameRunning = true;
				menuRunning = false;
				break;
			case 2:
				cout << "(1) Easy" << endl;
				cout << "(2) Medium" << endl;
				cout << "(3) Hard" << endl;
				cin >> difficulty;
				break;
			case 3:
				cout << "Designed by Isaiah Lee." << endl;
				break;
			case 4:
				menuRunning = false;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "Invalid input." << endl;
		}
		//returns whether or not the game is running at conclusion
	}
	return gameRunning;
}