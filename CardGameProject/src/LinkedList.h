#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Card.h"

class LinkedList {
public:
	class Node {
	public:
		Card * data;
		Node * next;
		Node();
		Node(Card * data);
		Node(Card * data, Node * next);
	};
private:
	Node * head;
	Node * tail;
	int size;
	bool isEmpty();
	void insertAtHead(Card * data);
	void insertAtTail(Card * data);
	Card * removeAtHead();
	Card * removeAtTail();
public:
	LinkedList();
	//LinkedList(const LinkedList& l);
	//~LinkedList();
	int getCount();
	void grow();
	void shrink();
	void insertAtIndex(int index, Card * data);
	void remove(Card& data);
	Card * removeAtIndex(int index);
	int search(Card * data);
	Node* operator[](int i);	
	const LinkedList& operator=(LinkedList& other);
	friend const std::ostream& operator<<(std::ostream& os, LinkedList l);
};

	

#endif