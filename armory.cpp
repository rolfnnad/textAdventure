#include "armory.h"
#include "main.h"
#include <iostream>

void armory::armorSelect(int armorChoice) {
	int dexBonus = 0;
	switch (armorChoice) {
	case 0 :
		dexBonus = playerStats.get_abilityModifier(1);
		break;
	case 1 :
		dexBonus = playerStats.get_abilityModifier(1);
		if (dexBonus > 2) {
			dexBonus = 2;
		}
		break;
	case 2 :
		break;
	default :
		break;
	}
	playerStats.set_playerArmor(armorType[armorChoice-1] + dexBonus, armorName[armorChoice-1]);
	if (classFeatures.getDefense() == true) {
		playerStats.set_armorClass(1);
	}
	else {
		playerStats.set_armorClass(0);
	}
}