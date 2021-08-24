#include "races.h"
#include "main.h"

void races::setDwarf() {
	playerStats.setStat(2, 2);
}

void races::setElf() {
	playerStats.setStat(1, 2);
}

void races::setHuman() {
	int statType = 0;
	while (statType < 6) {
		playerStats.setStat(statType, 1);
		statType++;
	}
}