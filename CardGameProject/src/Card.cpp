#include <string>
#include <iostream>
#include "Card.h"

Card::Card(){
    suit = 0;
    rank = 0;
    value = 0;
}
Card::Card(int s, int r){
    suit = s;
    rank = r;
    value = 0;
}

Card::Card(int s, int r, int v){
    suit = s;
    rank = r;
    value = v;
}

void Card::setSuit(int s){
    suit = s;
}

void Card::setRank(int r){
    rank = r;
}

int Card::getSuit(){
    return suit;
}

int Card::getRank(){
    return rank;
}

/*
*   < 0 if less than
*   0 if equal
*   > 0 if greateer than
*/
int Card::compareTo(const Card& otherCard){
    return value - otherCard.value;
}

int Card::compareByRank(const Card& otherCard){
    return rank - otherCard.rank;
}

int Card::compareBySuit(const Card& otherCard){
    return suit - otherCard.suit;
}

 const std::ostream& operator<<(std::ostream& os, Card& c){
    std::string suits[] = {"Spade", "Hearts", "Diamond", "Club"};
    std::string ranks[] = {"Ace", "2","3", "4","5","6","7","8","9","10","Jack","Queen","King"};
    os << "Card " << ranks[c.rank] << " " << suits[c.suit] << " " << c.value << std::endl;
    return os;
}

const std::istream& operator>>(std::istream& is, Card& c){
    std::cout << "Enter value of card" << std::endl;
    is >> c.value;
    std::cout << "Enter rank of card" << std::endl;
    is >> c.rank;
    std::cout << "Enter suit of card" << std::endl;
    is >> c.suit;
    return is;
}


