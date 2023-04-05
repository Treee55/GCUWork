#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "Player.h"
#include "Arena.h"
#include "Store.h"

using namespace std;
class Movement
{
private:
	string cName;// for name of player
	int cArena = 1, cWeap = 1, cHealth = 100, cMoney = 30, pick;
	fstream thatFile; // allows for saving of the game

public:
	Player* competitor = new Player; //player pointer
	Movement();
	void buildChar();
	void saveGame();
	void enterArena();
	void goStore();
	void replay();
};
