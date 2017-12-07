#include <string>
#include "Card.h"
#include "Stack.h"
#ifndef DECK_H
#define DECK_H

class Deck{
private:
    Stack<Card> deck;
    int remainingCards;
    int capacity;
public:
    Deck();
    // setters
    int getRemainingCards();
    Stack<Card> getDeck();
    int getCapacity();
    void shuffle();
    Card* deal();
    void createDeck();
    bool isFull();

    friend const std::ostream& operator<<(std::ostream& os, Deck& d);
    friend const std::ostream& operator>>(std::ostream& os, Deck& d);
    
};
#endif