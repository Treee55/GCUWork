#include "Player.h"



Player::Player(string n, int w, int h, int m, int a) // takes in all the values to create the player. Has money and the arena that is to be played in unlike the enemy.
{
	name = n;
	weapon = w;
	health = h;
	money = m;
	arena = a;
}

Player::Player(string n, int w, int h) // creates enemies in arena
{
	name = n;
	weapon = w;
	health = h;
}
// Many of these could be combined into a single or one less class. This was not done to keep confusion down while writting the program
Player::Player()
{
}

string Player::showName()// gets the player name
{
	return name;
}

int Player::showHealth() // makes sure the player doesnt have over 200 health. As well not under 100 health
{
	if (health >= 200) {
		health = 200;
	}
	if (health <= 0) {
		health = 0;
	}
	return health;
}
string Player::getWeap() // Returns the string value of the weapon to the screen. Not just numbers
{
	if (weapon == 1) {
		return "Knife";
	}
	if (weapon == 2) {
		return "Hammer";
	}
	if (weapon == 3) {
		return "Sword";
	}
	if (weapon == 4) {
		return "Hatchet";
	}
	if (weapon == 5) {
		return "EnergySword";
	}
	if (weapon == 6) {
		return "Gamender";
	}
	else {
		return "";
	}
}

int Player::showWeap() //gets int value of weapon. Different from displaying the actual weapon
{
	return weapon;
}

int Player::showMoney() // returns int of money
{
	return money;
}

int Player::showArena() //controls what arena is to be played in. Returns this value
{
	return arena;
}


void Player::changeArena(int c, int a)// changes the arena after a win. allows player to go back and replay game.
{
	if (a == 1) {
		arena += 1;
	}
	if (a == 2) {
		arena = c;
	}
}

int Player::changeHealth(int h, int c) // health that is increased when bought or during fight. Health goes down when hit in fight
{
	if (c == 1) {
		health += h;
		return h;
	}
	if (c == 2) {
		health -= h;
		return h;
	}

}


void Player::changeweap(int w) // new weapon that is bought
{
	weapon = w;
}

void Player::changeMoney(int m, int c) // money taken from player when weapons are bought. Money given when player wins a fight.
{
	if (c == 1) {
		money += m;
	}
	if (c == 2) {
		money -= m;
	}
}