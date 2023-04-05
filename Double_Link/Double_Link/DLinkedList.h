#pragma once

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>
using namespace std;

template <class T> //universal type that can be passed around. reminds me of python in some ways

class DLinkedList {
	friend ostream& operator << (ostream& out, const DLinkedList<T>& rhs) { 
		DNode* curr = rhs.header->next;              //in basics works with the file retrevial? Is a friend and can be accessed from most anywhere that it needs to be
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}
public:
	class DNode {
	public:
		DNode* next; //creates the next pointer
		DNode* prev; //creates the past pointer
		T data; //holds our data

		DNode(T val = T()) {  //solidifys what is in the Node. With data type, and where things are pointing
			data = val;
			next = prev = this;
		}
	};

	DLinkedList() { //base constructor that creates our lists
		header = new DNode();
	}

	DNode* add(T item) { //O(n)
		DNode* newNode = new DNode(item); //new node with new data
		newNode->prev = header; //previous pointer pointing to the header 
		newNode->next = header->next; // pointing to what the pointer is pointing to
		header->next->prev = newNode; //headers next previous pointer is pointing back to the head
		header->next = newNode; //new nodes next is pointing to whatever the header was pointing to
		return newNode;
	}
	//O(n), this must go through each point and move pointers around to "delete it". Tricky to use because if it is used to early it kills everything...
	bool remove(T val) { //removes a value from the list.
		DNode* temp = header->next; // sets the temp to be where the header would be
		while (temp != header) { //the temp is not at the end
			if (temp->data == val) { // if the temp->data is the same as the value being passed in.
			
				if (temp->prev == NULL) { //if the prev is null then do this
					header = temp->next; // header points past what the the temp was
					header->prev = NULL; // the headers previous points to null making it a full fix
					return false;
				}
				else if (temp->next == NULL) { // if the value is at the end of the list
					temp->prev->next = NULL; // makes the temps previous pointer next point to NULL	
					return false;
				}
				else { //if the data pointers are not equal to NULL
					temp->prev->next = temp->next; //past pointer points to the next node in the line
					temp->next->prev = temp->prev; // next pointer points to the previous
					return false;
				}
			}
			temp = temp->next;
		}
		return true;
	}
	//O(n) this creates a unknown amount of nodes that hold unknown data. Cannot be O(1) as is is not simply returning something
	void insertOrder(T item) { //new data is passed into the function //given from sarlo. 
		DNode* newDNode = new DNode(item);                              // new node containing the new data
		DNode* temp = header->next;                                     // temp->next is same as the header->next

		while (temp->data <= newDNode->data && temp != header) { temp = temp->next; }    // loop to know where to insert the new data

		if (temp->next == header && temp->data <= newDNode->data) {      // checks if the data is less than the final node
			newDNode->next = temp->next;                                // inserts node before the last value
			newDNode->prev = temp;

			temp->next->prev = newDNode; //most confusing. points to the next temp node, then tells the next node to point to the nodes previous
			temp->next = newDNode;
		}
		else if (temp == header && temp->data >= newDNode->data) {     // checks if the data is greater than the final node
			newDNode->next = temp;                                      // inserts node after the last value
			newDNode->prev = temp->prev;
			temp->prev->next = newDNode; //newDNode points to the previous nodes next pointer
			temp->prev = newDNode;
			header = newDNode;                                          // reassign header node
		}
		else {                                                        // inserts node for all other cases
			newDNode->next = temp;
			newDNode->prev = temp->prev;
			temp->prev->next = newDNode;
			temp->prev = newDNode;
		}
	}

	bool insertOrderUnique(T val) { //O(n) the list is not set, so it has n amounts to go through.
		if (!contains(val)) {
			insertOrder(val); //inserts the value into the correct place
			return true;
		}
		return false;
	}

	DLinkedList merge(DLinkedList rhs) { //O(n) as not known how large the list will be. lst1 and lst2 can vary
		DLinkedList result; //new list that is to be built
		DNode* temp = header->next;
		while (temp != header) { //while not at the end do this.
			result.insertOrderUnique(temp->data); //result is built off of unique order of all lst1 values being passed in.
			temp = temp->next; //increments
		}
		temp = rhs.header->next; // resets temp to be lst2 as this was passed in
		while (temp != rhs.header) {
			result.insertOrderUnique(temp->data); //same as above
			temp = temp->next;
			remove(temp->data);
		}
		return result;
	}

private:
	DNode* header;//this is the start of either list. header is annoying but I figured it out
	
	bool contains(T items) { //this checks to see if there is any repition... repetition? repetitive
		DNode* curr = header->next;
		while (curr != header) { //while our curr is not to the end of the list
			if (curr->data == items) { //if the data is the same, we return true, thus this value will not be passed in.
				return true;
			}
			curr = curr->next; // incriment
		}
		return false;
	}
};

#endif // !DLINKEDLIST