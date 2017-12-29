#ifndef HAND_H
#define HAND_H

#include "LinkedList.cpp"
#include <string>

class Hand {
private:
	LinkedList<Card> * hand;
public:
	Hand();
	LinkedList<Card>* getHand();
	int countRank(int rank);
	int evaluate();
	Card* getCardAt(int index);
	void removeCardAt(int index);
	int getCount();
	bool hasRank(int rank);
	void insertByRank(Card * card);
	bool isEmpty();
	std::string display();
};
#endif