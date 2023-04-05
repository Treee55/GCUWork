#pragma once
#include <iostream>
#include <string>
using namespace std;
struct node {
	string data;
	struct node* left;
	struct node* right;
}
;
class tree
{
private: 
	int count;
public:
	struct node* head;
	tree();
	node* insert(string str, node* head);
	node* deleteNode(struct node* node, string key);
	node* minValueNode(struct node* node);
	void put(string str);
	void displaytree();
	void displaying(node* node);
	bool search(node* node, string key);
	void startsearch(string key);
	void deleting(string key);
};