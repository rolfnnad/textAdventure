#ifndef ARMORY_H
#define ARMORY_H
#include <string>

using namespace std;

class armory
{
public:
	void armorSelect(int armorChoice);
private:
	int armorType[3] = { 1, 4, 6 };
	string armorName[3] = { "Leather Armor", "Scale Mail", "Chain Mail" };
};

#endif