#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include <string>

class Hand {
private:
	LinkedList * hand;
public:
	Hand();
	LinkedList getHand();
	int countRank(int rank);
	int evaluate();
	Card* getCardAt(int index);
	int getCount();
	bool hasRank(int rank);
	void insertByRank(Card * card);
	bool isEmpty();
	std::string display();
};
#endif