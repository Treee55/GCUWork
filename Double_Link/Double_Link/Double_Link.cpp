// Parker Spaan

#include "DLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;

	ifstream fin("txt1.in");
	string str;

	fin.open("txt1.txt");
	while (fin >> str) {
		str = cleanUp(str);
		lst1.insertOrderUnique(str);
	}
	fin.close();

	fin.open("txt2.txt");
	while (fin >> str) {
		str = cleanUp(str);
		lst2.insertOrderUnique(str);
	}
	fin.close();
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;

	DLinkedList<string> combined = lst1.merge(lst2);

	cout << "\nAFTER MERGE" << endl;
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	cout << "\nCombined: " << combined << endl;
	return 0;
}
string cleanUp(string str) {

	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 65 || str[i] > 122) {
			str[i] = NULL;
			continue;
		}
		else if (str[i] < 97 && str[i]> 65) {
			str[i] += 32;
		}
	}
	return str;
}