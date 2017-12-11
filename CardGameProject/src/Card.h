#include <string>
#include <iostream>
#ifndef CARD_H
#define CARD_H

class Card{
private:
    int value;
    int suit;
    int rank;
public:
    Card();
    Card(int r, int s);
    Card(int r, int s, int v);

    // setters
    void setSuit(int s);

    void setRank(int r);
    void setValue(int v);
    // getters

    int getSuit();

    int getRank();
    int getValue();
    int compareTo(const Card& otherCard);
    int compareByRank(const Card& otherCard);
    int compareBySuit(const Card& otherCard);
    friend const std::ostream& operator<<(std::ostream& os, Card& c);
    friend const std::istream& operator>>(std::istream& is, Card& c);
};
#endif