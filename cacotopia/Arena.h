#pragma once
#include <fstream>;
#include "Player.h";
class Arena
{
private:
	Player* enemy = new Player; //pointer of enemy 
	string eName; // enemy name
	int eHealth, eWeap, move, damage, regen = 1; // info for name, as well the move to be done
	fstream thisFile;

public:
	Arena();
	Arena(string n, int h, int w); //taken from movment to build enemy
	void fight(Player* competitor); //passes in player to the arenas
	void attack(Player* competitor); // passes in player to fight with weapon
};