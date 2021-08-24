#include "features.h"
#include "main.h"
#include <iostream>

void features::setCleric(int classChoice) {
	playerStats.set_playerClass(classNames[classChoice - 1]);
	playerStats.set_hitPoints(8);
	playerStats.set_armorClass(0);
}

void features::setFighter(int classChoice) {
	playerStats.set_playerClass(classNames[classChoice - 1]);
	playerStats.set_hitPoints(10);
	playerStats.set_armorClass(0);
	set_fightingStyle();
}

void features::setWizard(int classChoice) {
	playerStats.set_playerClass(classNames[classChoice - 1]);
	playerStats.set_hitPoints(6);
	playerStats.set_armorClass(0);
}

void features::set_fightingStyle() {
	int styleChoice = 0;
	cout << "Choose your fighting style." << endl << endl;
	cout << "(1) Archery (You gain a +2 bonus to attack rolls you make with ranged weapons)" << endl;
	cout << "(2) Defense (While wearing armor, you gain a +1 bonus to AC)" << endl;
	cout << "(3) Dueling (When you are wielding a melee weapon in one hand and no other weapons, you gain a +2 bonus to damage rolls with that weapon." << endl;
	while (styleChoice < 1 || styleChoice > 3) {
		cin >> styleChoice;
		switch (styleChoice) {
		case 1:
			break;
		case 2:
			defense = true;
			break;
		case 3:
			break;
		default:
			cout << "Choose a valid number~!!" << endl;
			break;
		}
	}
}

bool features::getDefense() {
	return defense;
}