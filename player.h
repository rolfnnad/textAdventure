#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class player
{
public:
	void setStat(int statType, int statModifier);
	int getStat(int statType);
	int get_abilityModifier(int statType);
	string get_abilityName(int statType);
	void resetStats(int statType);
	int get_armorClass();
	void set_armorClass(int armorBonus);
	void set_playerArmor(int armorType, string armorName);
	void set_playerClass(string classChoice);
	void set_hitPoints(int hitDie);
	int get_hitPoints();
	string get_playerClass();
	string get_playerArmorName();
private:
	int stats[6] = { 8,8,8,8,8,8 };
	int abilityModifier[6] = { -1, -1, -1, -1, -1, -1 };
	string abilityName[6] = { "Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma" };
	int armorClass;
	int playerArmor;
	string playerArmorName;
	int hitPoints = 0;
	string playerClass;
};

#endif