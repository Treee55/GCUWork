// Parker Spaan

#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;

void drive() {
	ifstream thatFile;
	thatFile.open("words.txt"); //open our text file
	if (!thatFile.is_open()) { //if its doesnt open pop an error
		cout << "error occured";
		exit(1);
	}
	else {
		tree play;
		string word;
		while (thatFile >> word) { //while we read each word from the file
			play.put(word); //sending to our helper method
		}
		thatFile.close();
		int val, i = 0;
		while (i != -1) { //while we arent exited
			cout << "The sorted list is: ";
			play.displaytree();// display the sorted data
			cout << "\n -1 to exit\t[1] to search\t[2] to delete a value\n >"; //getting what the user wants inputted
			cin >> val;
			if (val == 1) {
				string key;
				cout << "What word are you looking for?\n >";
				cin >> key;
				play.startsearch(key); // passes the word in that is being searched for
			}
			else if (val == 2) { // call the delete method
				string key;
				cout << "What word would you like to remove?\n >";
				cin >> key;
				play.deleting(key);
			}
			else if (val == -1) {//ends the loop and program
				break;
			}
			else { //whatever is sent in doesnt work
				cout << "Invalid please try again" << endl;
			}

		}

	}
}

int main()// O(n) until we search and becomes O(log(n))
{
	drive();
	return 0;
}


