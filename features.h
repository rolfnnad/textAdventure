#ifndef FEATURES_H
#define FEATURES_H
#include <string>

using namespace std;

class features
{
public:
	void setCleric(int classChoice);
	void setFighter(int classChoice);
	void setWizard(int classChoice);

	void set_fightingStyle();
	bool getDefense();
private:
	string classNames[3] = { "Cleric", "Fighter", "Wizard" };
	string fightingStyleName[3] = { "Archery", "Defense", "Dueling" };
	int fightingStyle[3] = { 2, 1, 2 };
	bool defense = false;
};

#endif