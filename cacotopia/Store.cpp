#include "Store.h"

Store::Store()
{
}

void Store::buyHealth(Player* competitor, int c)
{
	switch (c) {
	case 1: {
		cout << competitor->showName() << " owns weapon [" << competitor->getWeap() << "] has health of [" << competitor->showHealth() << "] and has [$" << competitor->showMoney() << "]\n";
		cout << "[1] Health: +30   CAN OF POP $50 \n[2] Health: +50   SYRINGE $75 \n[3] Health: +75   MEDPACK $100 \n[4] Health: +100   HOSTPITAL $150 \n[5] LEAVE\n >";
		cin >> pick;
		switch (pick) { //takes in the choice that is made from above, and changes the players health
		case 1:
		{
			if (competitor->showMoney() < 50) { //checks to make sure their money is ennough to buy the product
				cout << "You cannot buy this" << endl;// if not cannot buy
				break;
			}
			else {
				cout << "+30 Health added." << endl; //says the health added
				competitor->changeHealth(30, 1); // adds the health
				competitor->changeMoney(50, 2); // takes money from player
			}
			break;
		}
		case 2:
		{
			if (competitor->showMoney() < 75) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << "+50 Health added." << endl;
				competitor->changeHealth(50, 1);
				competitor->changeMoney(75, 2);
			}
			break;
		}
		case 3:
		{
			if (competitor->showMoney() < 100) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << "+75 Health added." << endl;
				competitor->changeHealth(75, 1);
				competitor->changeMoney(100, 2);
			}
			break;
		}
		case 4:
		{
			if (competitor->showMoney() < 150) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << "+100 Health added." << endl;
				competitor->changeHealth(100, 1);
				competitor->changeMoney(150, 2);
			}
			break;
		}
		case 5: {
			break;
		}
		};
		break;
	}
	case 2: {
		cout << competitor->showName() << " owns weapon [" << competitor->getWeap() << "] has health of [" << competitor->showHealth() << "] and has [$" << competitor->showMoney() << "]\n";
		cout << "[1]   KNIFE $FREE \n[2]   HAMMER $25 \n[3]   SWORD $300 \n[4]   HATCHET $425 \n[5]   ENERGYSWORD $750 \n[6]   GAMENDER $1250 \n[7]   LEAVE \n>";
		cin >> pick;
		switch (pick) //all of these change the weapon that is in the players hand and in the arena what their attacks will be
		{
		case 1:
		{
			cout << "You bought another knife! Useless but ok." << endl; //done buy this one
			competitor->changeweap(1);
			break;
		}
		case 2:
		{
			if (competitor->showMoney() < 25) { //checks if player has enough money
				cout << "You cannot buy this" << endl; //kicks then if not enough
				break;
			}
			else {
				cout << competitor->showName() << " bought a hammer. Goodluck in there. \nYOU HAVE BOUGHT A WEAPON THAT REGAINS HEALTH. USE WISELY IN YOUR FIGHTS, YOU CAN ONLY USE IT ONCE A FIGHT." << endl;
				competitor->changeweap(2); // changes weapon
				competitor->changeMoney(25, 2); // takes money away
			}
			break;
		}
		case 3:
		{
			if (competitor->showMoney() <= 300) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << competitor->showName() << " bought a Sword. Maybe you get through with this.\nYOU HAVE BOUGHT A WEAPON THAT REGAINS HEALTH. USE WISELY IN YOUR FIGHTS, YOU CAN ONLY USE IT ONCE A FIGHT." << endl;
				competitor->changeweap(3);
				competitor->changeMoney(300, 2);
			}
			break;
		}
		case 4:
		{
			if (competitor->showMoney() <= 425) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << competitor->showName() << " bought a Hatchet. Raising eyebrows in the arena.\nYOU HAVE BOUGHT A WEAPON THAT REGAINS HEALTH. USE WISELY IN YOUR FIGHTS, YOU CAN ONLY USE IT ONCE A FIGHT." << endl;
				competitor->changeweap(4);
				competitor->changeMoney(425, 2);
			}
			break;
		}
		case 5:
		{
			if (competitor->showMoney() <= 750) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << competitor->showName() << " bought an energysword. You just may make it out of this.\nYOU HAVE BOUGHT A WEAPON THAT REGAINS HEALTH. USE WISELY IN YOUR FIGHTS, YOU CAN ONLY USE IT ONCE A FIGHT." << endl;
				competitor->changeweap(5);
				competitor->changeMoney(750, 2);
			}
			break;
		}
		case 6:
			if (competitor->showMoney() <= 1250) {
				cout << "You cannot buy this" << endl;
				break;
			}
			else {
				cout << competitor->showName() << " bought the Gamender... good game." << endl;
				competitor->changeweap(6);
				competitor->changeMoney(1250, 2);
				break;
			}
		case 7: {
			break;
		}
		};
		break;
	}
	}
}