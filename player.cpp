#include "player.h"
#include "main.h"

void player::setStat(int statType, int statModifier) {
	stats[0 + statType] = stats[0 + statType] + statModifier;
	abilityModifier[statType] = stats[statType] - 10;
	abilityModifier[statType] = abilityModifier[statType] / 2;
}

int player::getStat(int statType) {
	return stats[0 + statType];
}

int player::get_abilityModifier(int statType) {
	return abilityModifier[statType];
}

string player::get_abilityName(int statType) {
	return abilityName[0 + statType];
}

void player::resetStats(int statType) {
	while (statType < 6) {
		stats[statType] = 8;
		statType++;
	}
}

void player::set_armorClass(int armorBonus) {
	armorClass = 10 + playerArmor + armorBonus;
}

int player::get_armorClass() {
	return armorClass;
}

void player::set_playerArmor(int armor, string armorName) {
	playerArmor = armor;
	playerArmorName = armorName;
}

void player::set_playerClass(string classChoice) {
	playerClass = classChoice;
}

void player::set_hitPoints(int hitDie) {
	hitPoints = hitPoints + hitDie + abilityModifier[2];
}

int player::get_hitPoints() {
	return hitPoints;
}

string player::get_playerClass() {
	return playerClass;
}

string player::get_playerArmorName() {
	return playerArmorName;
}