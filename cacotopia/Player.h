#pragma once
#include <string>
#include <iostream>
using namespace std;
class Player
{
private:
	string name = " ";//sets name just within this class. Both movement and player need this. One to build, the other to hold. Annoying but needed
	int weapon, health, money, arena;// default stats that will be manipulated
public:
	Player(string n, int w, int h, int m, int a);
	Player(string n, int w, int h);
	Player();

	string showName();
	string getWeap();

	int showHealth();
	int showWeap();
	int showMoney();
	int showArena();

	void changeArena(int c, int a);
	int changeHealth(int h, int c);
	void changeweap(int w);
	void changeMoney(int m, int c);
};

