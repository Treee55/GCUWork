#include "Arena.h"
#include "Player.h"


Arena::Arena()
{
}

Arena::Arena(string n, int h, int w) //used to create the enemy
{
	eName = n;
	eHealth = h;
	eWeap = w;
	enemy = new Player(eName, eHealth, eWeap);//enemy is made
}

void Arena::fight(Player* competitor)
{
	cout << "Welcome to arena " << competitor->showArena() << endl << "\n--------- Competitor Stats: -------- \n  Name: " << enemy->showName() << "\n  Weapon: " << enemy->getWeap() << "\n  Health: " << enemy->showHealth() << "\n -----------------------------------" << endl;;
	int i = 0;
	while (i != -1) {// the whole fight is within this
		damage = 0;
		cout << "\n It is " << competitor->showName() << "s turn." << endl;
		attack(competitor);//goes to the attack and lets the player choose how they are to attack

		if (enemy->showHealth() >= 1) {// makes sure the player is still alive

			switch (competitor->showArena()) { //depending on the arena/ fighter the amount of damage that is given is made below.
			case 1: {

				damage = competitor->changeHealth(rand() % 5 + 3, 2);
				cout << "\nRue uses stab. This does [" << damage << "] damage to " << competitor->showName() << ". Health is now [" << competitor->showHealth() << "]" << endl;
				break;
			}
			case 2: {
				damage = competitor->changeHealth(rand() % 8 + 10, 2);
				cout << "\nGlimmer uses smash. This does [" << damage << "] damage to " << competitor->showName() << ". Health is now [" << competitor->showHealth() << "]" << endl;
				break;
			}
			case 3: {
				damage = competitor->changeHealth(rand() % 12 + 12, 2);
				cout << "\nMarvel uses Quick Swing. This does [" << damage << "] damage to " << competitor->showName() << ". Health is now [" << competitor->showHealth() << "]" << endl;
				break;
			}
			case 4: {
				damage = competitor->changeHealth(rand() % 25 + 12, 2);
				cout << "\nCato uses throw. This does [" << damage << "] damage to " << competitor->showName() << ". Health is now [" << competitor->showHealth() << "]" << endl;
				break;
			}
			case 5: {
				damage = competitor->changeHealth(rand() % 28 + 15, 2);
				cout << "\nSnow uses proton split. this does [" << damage << "] damage to " << competitor->showName() << ". Health is now [" << competitor->showHealth() << "]" << endl;
				break;
			}
			}
		}

		if (enemy->showHealth() <= 0 || competitor->showHealth() <= 0) { //ends game if either player is dead
			i = -1;
		}
	}

	if (competitor->showHealth() <= 0) {//player is dead. Program ends
		cout << "\nGAME OVER..." << endl;
		cout << "  _______________________________________________________" << endl;
		cout << " /                                                       \"" << endl;
		cout << " |                You will never be free                 |" << endl;
		cout << "  \_________              _______________________________/ " << endl;
		cout << "            %_         __/    ___---------__               " << endl;
		cout << "              %      _/      /              %_             " << endl;
		cout << "               %    /       /                  %           " << endl;
		cout << "               %  /        /                    |          " << endl;
		cout << "               |  /       |  _    _              |         " << endl;
		cout << "               | |       /  / \  / % |            |        " << endl;
		cout << "               | |       | |   ||  ||             |        " << endl;
		cout << "               | |       |   %_//\\_/ |           |        " << endl;
		cout << "               | |       |_| (||)   |_______|   |          " << endl;
		cout << "               | |         |  ||     | _  / /   |          " << endl;
		cout << "                % %        |_________|| %/ /   /           " << endl;
		cout << "                 % %_       |_|_|_|_|/|  _/___/            " << endl;
		cout << "                  %__> >>>    _ _/_ _ /  |                 " << endl;
		cout << "                            .|_|_|_|_|   |                 " << endl;
		cout << "                            |           /                  " << endl;
		cout << "                            |__________/                   " << endl;
		delete(competitor);
		thisFile.open("SaveGame.txt"); // Deletes all saved data. Start player over
		thisFile.close();
		exit(0);
	}
	else {
		system("CLS");
		cout << "\nCongratulations on defeating " << enemy->showName() << endl;
		delete(enemy);
		competitor->changeMoney(competitor->showArena() * (rand() % 100 + 100), 1);
		competitor->changeArena(0, 1);
		cout << competitor->showName() << " has health of " << competitor->showHealth() << " and now has $" << competitor->showMoney() << endl;
	}
}

void Arena::attack(Player* competitor)
{
	switch (competitor->showWeap()) { //Finds the weapon being used, as well what the damage of that weapon can do.
	case 1: { //knife
		cout << " ________________________________\n|\t     Choose attack       |\n|\t[1] Stab  {5-10}         |\n|\t[2] Stabby Stab  {4-14}  |\n|\t[3] Stab Yourself        |\n --------------------------------\n>";
		cin >> move;
		system("CLS");
		switch (move) {
		case 1: {
			damage = enemy->changeHealth(rand() % 5 + 5, 2);// area of damage that can be done.
			cout << competitor->showName() << " stabs " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl; // says what is being done and shows new health/
			break;
		}
		case 2: {
			damage = enemy->changeHealth(rand() % 10 + 4, 2);
			cout << competitor->showName() << " uses stabby stab on " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 3: {
			damage = competitor->changeHealth(100, 2);
			cout << competitor->showName() << " stabs themselves for some f@&!*** reason. Health is now [" << competitor->showHealth() << "]" << endl;
			break;
		}
		default: {
			cout << "Not valid. Missed your turn." << endl;
			break;
		}
		}
		break;
	}
	case 2: {// hammer
		cout << " ___________________________\n|\tChoose attack       |\n|\t[1] Smash  {8-14}   |\n|\t[2] Hook  {7-19}    |\n|\t[3] Throw  {4-25}   |\n|\t[4] Heal            |\n ---------------------------";
		cout << "\nHealths left to use [" << regen << "].\n>";
		cin >> move;
		system("CLS");
		if (move == 4 && regen == 0) {
			cout << "Out of healing. [1] is being used" << endl;
			move = 1;
		}
		switch (move) {
		case 1: {
			damage = enemy->changeHealth(rand() % 6 + 9, 2);
			cout << competitor->showName() << " smashes " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 2: {
			damage = enemy->changeHealth(rand() % 12 + 8, 2);
			cout << competitor->showName() << " hooks " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 3: {
			damage = enemy->changeHealth(rand() % 21 + 5, 2);
			cout << competitor->showName() << " throws their hammer at " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 4: {
			competitor->changeHealth(10, 1);
			cout << competitor->showName() << " heals [10] and their health is now [" << competitor->showHealth() << "]." << endl;
			regen--;
			break;
		}
		default: {
			cout << "Not valid. Missed your turn." << endl;
			break;
		}
		}
		break;
	}
	case 3: { //sword
		cout << " _________________________________\n|\t    Choose attack         |\n|\t[1] Big Swing  {15-18}    |\n|\t[2] Quick swing {13-21}   |\n|\t[3] Handle breaker {12-30}|\n|\t[4] Heal                  |\n ---------------------------------";
		cout << "\nHealths left to use [" << regen << "].\n>";
		cin >> move;
		system("CLS");
		if (move == 4 && regen == 0) {
			cout << "Out of healing. [1] is being used" << endl;
			move = 1;
		}
		switch (move) {
		case 1: {
			damage = enemy->changeHealth(rand() % 3 + 16, 2);
			cout << competitor->showName() << " takes big swing at " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 2: {
			damage = enemy->changeHealth(rand() % 8 + 14, 2);
			cout << competitor->showName() << " takes a quick swing at " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 3: {
			damage = enemy->changeHealth(rand() % 18 + 13, 2);
			cout << competitor->showName() << " breaks " << enemy->showName() << " handle. This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 4: {
			competitor->changeHealth(25, 1);
			cout << competitor->showName() << " heals [25] and their health is now [" << competitor->showHealth() << "]." << endl;
			regen--;
			break;
		}
		default: {
			cout << "Not valid. Missed your turn." << endl;
			break;
		}
		}
		break;
	}
	case 4: { //Hatchet
		cout << " __________________________________\n|\t     Choose attack         |\n|\t[1] Hatchet Slash  {24-31} |\n|\t[2] Achilles Swing  {22-37}|\n|\t[3] Shadow throw  {15-43}  |\n|\t[4] Heal                   |\n ----------------------------------";
		cout << "\nHealths left to use [" << regen << "].\n>";
		cin >> move;
		system("CLS");
		if (move == 4 && regen == 0) {
			cout << "Out of healing. [1] is being used" << endl;
			move = 1;
		}
		switch (move) {
		case 1: {
			damage = enemy->changeHealth(rand() % 7 + 28, 2);
			cout << competitor->showName() << " Hatchet Slashes " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 2: {
			damage = enemy->changeHealth(rand() % 15 + 22, 2);
			cout << competitor->showName() << " Achilles Swings " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 3: {
			damage = enemy->changeHealth(rand() % 28 + 15, 2);
			cout << competitor->showName() << " Shadow Throws at " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 4: {
			competitor->changeHealth(35, 1);
			cout << competitor->showName() << " heals [35] and their health is now [" << competitor->showHealth() << "]." << endl;
			regen--;
			break;
		}
		default: {
			cout << "Not valid. Missed your turn." << endl;
			break;
		}
		}
		break;
	}
	case 5: { //energy sword
		cout << " ________________________________\n|\t   Choose attack         |\n|\t[1] Energy Swing  {15-20}|\n|\t[2] Proton Split  {13-25}|\n|\t[3] Energy burst  {11-45}|\n|\t[4] Heal                 |\n --------------------------------";
		cout << "\nHealths left to use [" << regen << "].\n>";
		cin >> move;
		system("CLS");
		if (move == 4 && regen == 0) {
			cout << "Out of healing. [1] is being used" << endl;
			move = 1;
		}
		switch (move) {
		case 1: {// eh
			damage = enemy->changeHealth(rand() % 5 + 15, 2);
			cout << competitor->showName() << " Energy Swings at " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 2: {
			damage = enemy->changeHealth(rand() % 14 + 12, 2);// decent attack
			cout << competitor->showName() << " Proton Splits " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 3: {
			damage = enemy->changeHealth(rand() % 34 + 11, 2);// very very strong attack
			cout << competitor->showName() << " Energy Bursts " << enemy->showName() << ". This does [" << damage << "] damage. Their health is now [" << enemy->showHealth() << "]" << endl;
			break;
		}
		case 4: {
			competitor->changeHealth(40, 1);
			cout << competitor->showName() << " heals [40] and their health is now [" << competitor->showHealth() << "]." << endl;
			regen--;
			break;
		}
		default: {
			cout << "Not valid. Missed your turn." << endl;
			break;
		}
		}
		break;
	}
	case 6: {// if weapon is aquired game is over
		cout << " ___________________________\n|\tChoose attack       |\n|\t[1] EndGame          |\n|\n ---------------------------\n>";
		cin >> move;
		system("CLS");
		damage = enemy->changeHealth(200, 2);// kills anyone
		cout << competitor->showName() << " ends the game on " << enemy->showName() << " they are dead dead.";
		break;
	}
	}
}