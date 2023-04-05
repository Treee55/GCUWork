#pragma once
#include <iostream>
#include "Movement.h"
#include "Player.h"
using namespace std;
class Store
{
private:
	int pick;// just allows the user to pick different things in the store
public:
	Store();
	void buyHealth(Player* competitor, int c);
};