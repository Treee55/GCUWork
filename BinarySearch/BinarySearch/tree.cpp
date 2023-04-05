#include "tree.h"

using namespace std;
tree::tree()
{
}
void tree::put(string str) //helper
{
	head = insert(str, head); //head points to everthing that is brought back
}

node* tree::insert(string str, node* node)//string and node (head to start) are passed in
{
	if (node == NULL) {//if the node is null
		struct node* node = new struct node;//new node is made
		node->data = str;// data of the node is from the str passed in
		node->left = NULL;//the left pointer points to null
		node->right = NULL; // right pointer points to null
		return node; //return this to the stack
	}
	else { //the node is not NULL

		if (str > node->data) { //if the str is larger than the data that is in the head 
			node->right = insert(str, node->right); //we move to the right and pass the value recursively back through to build to the right
		}
		else if (str == node->data) {
			return node; //if this value is already there returning that node not making a new one
		}
		else {//str is smaller than  the value in the node so we go left
			node->left = insert(str, node->left);//node->left points to the new node created through recursive call. Data is passed in and continues
		}
		return node;//returning at the end the nodes
	}
}

void tree::displaytree() //helper method to display
{
	displaying(head); //display and passing the head in to begin.
}

void tree::displaying(node* node) //node is passed in
{
	if (node != NULL)//if the node isnt null
	{
		displaying(node->left); //pass in this value (node to the left) once it hits null it will stop doing this
		cout << node->data << " "; //cout the data of the node that is not null
		displaying(node->right); //moving the node to the right
	}

}

bool tree::search(node* node, string key)//passing in our start and the key to be searched for.   O(log(n))
{
	if (node == NULL) { //once the node comes back as null it is false
		return false;
	}
	else if (node->data == key) {// if what is passed in is true then return true
		cout << "Seached "<< count << " elements ";
		count = 0;
		return true;
	}
	else if (key < node->data) { //if the key is less than or equal to the value
		count++;
		return search(node->left, key); //pass in the left node to be searched
	}
	else {
		count++;
		return search(node->right, key); //pass in the to the right to be searched
	}
	
}
void tree::startsearch(string key)
{
	if (search(head, key) == 1) { //if the word is found
		cout << "The word was found" << endl;
	}
	else {
		cout << "Word is not in the tree" << endl; // if the word is not found
	}
}
void tree::deleting(string key) //helper method
{
	deleteNode(head, key);
}
node* tree::deleteNode(node* node, string key) //this searchs through and deletes nodes that are needed (logic adapted from java stack overflow)
{
	if (node == NULL) {//if the node is null then that is all
		cout << "Word is not in the tree. Please try another" << endl;
		return node;
	}

	if (key < node->data) {    //if the key is less than the data
		node->left = deleteNode(node->left, key);  //move to the left
	}


	else if (key > node->data) { //if the key is creater than the data
		node->right = deleteNode(node->right, key); //moving to the right
	}

	//if the key == the data
	else {
		if (node->left == NULL && node->right == NULL) { // node is at the bottom no where to go
			return NULL; //deletes that data nothing else is needed
		}
		else if (node->left == NULL) { //only the left side is null pointing to the right still
			struct node* temp = node->right; //temp node is the node to the right
			delete(node); // deletes the node that is found
			return temp; //temp goes onto the stack. Not "rebuilding" as much displaying correctly what is where
		}
		else if (node->right == NULL) { //same as above but other direction
			struct node* temp = node->left;
			delete(node);
			return temp;
		}
		else {  //if the node has "two children" we look first for the left right sides minimum; see how far we must go
			struct node* temp = minValueNode(node->right); //finding the lowest value on that side of the tree
			node->data = temp->data; // whatever is on that side we will take its data
			node->right = deleteNode(node->right, temp->data);//once it is all taken, the right pointer will point to whatever is there after deletion.
		}
	}
	return node;
}
node* tree::minValueNode(node* node) //helper method to aid in understanding and for the delete (stackoverflow)
{
	struct node* temp = node; //right node is passed in
	while (temp && temp->left != NULL)//loop down until we get to the furthest left
		temp = temp->left; //makes temp whatever the left is
	return temp; //return that
};