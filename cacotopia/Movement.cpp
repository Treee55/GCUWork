#include "Movement.h"


Movement::Movement()
{
	cout << "New game [1]\tLoad previous save [2]" << endl;
	cin >> pick;
	if (pick == 1) {//if no load. Build the character

		string prompt = "Welcome back to CacoTopia. You have been captured trying to exit our perfect city. \n\nFor this act of treason you will be forced to fight to regain your freedom.\n\nThere are five opponents ahead of you. Each of them will be harder to kill than the last until you meet SNOW...\n\nIf you want to get back to living in beautiful CacoTopia follow these directions."
			"\n\nAfter getting your name you will ONLY use your num pad.\n\nAfter each fight (being you survive) you will be prompeted to the store. \n\nThere you will be able to buy back health and new weapons that have increasing damage to your opponent. \n\nWith each weapon the damage they do will not be the same everytime you use the attack. \n\nCan't have a perfect hit everytime can we?\n\nLast bit of advice. Don't die. This isn't like a videogame. \n\nYou dont come back. ";
		int x = 0;
		while (prompt[x] != '\0') {
			cout << prompt[x];
			Sleep(25);
			x++;
		}
		buildChar();
	}
	else {
		thatFile.open("SaveGame.txt"); //loads up whatever is saved in the game
		thatFile >> cName >> cWeap >> cHealth >> cMoney >> cArena;
		competitor = new Player(cName, cWeap, cHealth, cMoney, cArena);
		thatFile.close();
	}

	int i = 0;
	while (i != -2) {//entire game is run from here. Three options of what to do.
		if (competitor->showArena() <= 5) {
			cout << "\n         _____________________________" << "\n        |         CacoTopia           |\n\n        |   [1]Enter the Caco Store   |\n\n        |   [2]Enter the arena        |\n\n        |   [3]SAVE GAME              |\n         -----------------------------" << endl;
			cout << competitor->showName() << " owns weapon [" << competitor->getWeap() << "] has health of [" << competitor->showHealth() << "] and has [$" << competitor->showMoney() << "] \n>";
			cin >> i;
		}
		else {
			cout << "\n         _____________________________" << "\n        |         CacoTopia           |\n\n        |   [1]Enter the Caco Store   |\n\n        |   [2]Replay enemy           |\n\n        |   [3]SAVE GAME              |\n         -----------------------------" << endl;
			cout << competitor->showName() << " owns weapon [" << competitor->getWeap() << "] has health of [" << competitor->showHealth() << "] and has [$" << competitor->showMoney() << "] \n>";
			cin >> i;
			if (i == 2) {
				i = 4;
			}
		}
		switch (i) {
		case 1: {
			system("CLS"); // clearing all of the old text so its clean for the store.
			goStore();
			break;
		}
		case 2: {
			system("CLS");
			enterArena();
			break;
		}
		case 3: {
			saveGame();
			break;
		}
		case 4: {
			replay();
			break;
		}
		default:
			cout << "Not an option." << endl; //Try again
			system("CLS");
			break;
		}
	}
}

void Movement::buildChar() //gets information as to the name of the player. Then sets all of their stats to the defaults that were created.
{
	cout << "\n\nWhat is your name \n >";
	cin >> cName;
	cout << cName << " is given a Knife. Has health of 100, and is gifted $25";
	thatFile.open("SaveGame.txt");
	thatFile << cName << endl;
	thatFile << cWeap << endl;
	thatFile << cHealth << endl;
	thatFile << cMoney << endl;
	thatFile << cArena << endl;
	thatFile.close();
	competitor = new Player(cName, cWeap, cHealth, cMoney, cArena);// building actual player
}


void Movement::enterArena() //Where fighting happens could have made an array or vector. Did not for this as hard coding was faster. Easy to add more fights. Can switch to array if needed.
{
	string prompt = " ";
	int x = 0;
	switch (competitor->showArena()) { //finding which arena the player is to fight in. then building that arena here
	case 1:

	{Arena* arena1 = new Arena("Rue", 1, 50);
	arena1->fight(competitor);
	saveGame();
	prompt = "You beat Rue! Only four more fights until freedom!\n";
	while (prompt[x] != '\0') {
		cout << prompt[x];
		Sleep(50);
		x++;
	}
	break; }

	case 2:
	{Arena* arena2 = new Arena("Glimmer", 2, 100);// second fighter is named glimmer, has a hammer, and starts will 100 health
	arena2->fight(competitor);// passes competitor into the arena
	saveGame(); // saves the game after they leave the fight (if they leave)
	prompt = "Two fights in a row. Dont get too big of a head.\n";
	while (prompt[x] != '\0') {
		cout << prompt[x];                    //All of this is just to scroll the text. Something fun
		Sleep(50);
		x++;
	}
	break; }

	case 3:
	{Arena* arena3 = new Arena("Marvel", 3, 125);
	arena3->fight(competitor);
	saveGame();
	prompt = "Making noise in CacoTopia. \nMany of the citizens are talking about the people champion.\n";
	while (prompt[x] != '\0') {
		cout << prompt[x];
		Sleep(50);
		x++;
	}
	break; }

	case 4:
	{Arena* arena4 = new Arena("Cato", 4, 145);
	arena4->fight(competitor);
	saveGame();
	prompt = "You made it this far. Win one more fight and you are free to leave this violent life. \nGet what you need from the store.\nIts go time.\n";
	while (prompt[x] != '\0') {
		cout << prompt[x];
		Sleep(50);
		x++;
	}
	break; }

	case 5:
	{Arena* arena5 = new Arena("Snow", 5, 165);
	arena5->fight(competitor);
	saveGame();
	prompt = "I never expected you to make it out of there... \n\nBut now that you are. You must understand we need a new champion to take Snows place.\n\nThis life doesnt end for you, until its the end of your life.\n";
	while (prompt[x] != '\0') {
		cout << prompt[x];
		Sleep(50);
		x++;
	}
	break; }
	}
}

void Movement::saveGame() //Can save the game from the main screen. ALSO AUTO SAVES AFTER EACH FIGHT
{
	thatFile.open("SaveGame.txt");
	thatFile << competitor->showName() << endl;
	thatFile << competitor->showWeap() << endl;
	thatFile << competitor->showHealth() << endl;
	thatFile << competitor->showMoney() << endl;
	thatFile << competitor->showArena() << endl;
	thatFile.close();
}
void Movement::goStore()
{
	Store enter;
	int choose, i = 0;
	cout << "Welcome to Caco Weapons " << endl;
	cout << competitor->showName() << " owns weapon [" << competitor->getWeap() << "] has health of [" << competitor->showHealth() << "] and has [$" << competitor->showMoney() << "]";//displays stats
	while (i != 3) {
		cout << "\nWould you like to heal or deal some damage? \n [1] Heal \n [2] Weapons \n [3] EXIT STORE \n> ";
		cin >> choose;
		system("CLS");
		enter.buyHealth(competitor, choose);// brings player into the store.
		if (choose == 3) {// leaves the store
			i = 3;
		}
	}
	system("CLS");
}

void Movement::replay() //Just to allow for game reusability
{
	int i = 1;
	cout << " Who would you like to fight again? \n[1] RUE \n[2] GLIMMER \n[3] MARVEL \n[4] CATO \n[5] SNOW" << endl;
	cin >> i;
	competitor->changeArena(i, 2); //Whatever arena they want to enter
	enterArena();
	competitor->changeArena(6, 2); //sets them back to arena 6. Dont need to make them play through whole game again
}
