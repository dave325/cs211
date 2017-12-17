#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <string>
using namespace std;

class Player {
private:
	string name;
	Hand * hand;
	int points;
public:
	Player(string n);
	void setName(string name);
	string getName();
	void setPoints(int i);
	int getPoints();

	string playerInfo();
	string showHand();

	bool hasRank(int rank);
	void addCard(Card * card);
	Card * getCardAt(int index);
	int evaluateHand();

	int getTotalCards();
	void display();
};

#endif