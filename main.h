#ifndef MAIN_H
#define MAIN_H

#include "player.h"
#include "races.h"
#include "features.h"
#include "armory.h"
#include <string>
#include <iostream>

using namespace std;

extern player playerStats;

extern races playerRace;

extern features classFeatures;

extern armory equipment;

//function displays stats at will
void statsDisplay();

//ability select function
void abilitySelection();

//race select function
void raceSelection();

//class select function
void classSelection();

//equipment select function
void equipmentSelection();

//this function runs the character creation process
void characterCreation();

//this function runs the mainMenu process
int mainMenu();

#endif