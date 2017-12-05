#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Deck.h"
#include "Card.h"
#include "Stack.h"

Deck::Deck(){
    capacity = 52;
    remainingCards = 0;
    createDeck();
    shuffle();
}

int Deck::getRemainingCards(){
    return remainingCards;
}

int Deck::getCapacity(){
    return capacity;
}

Stack Deck::getDeck(){
    return deck;
}


void Deck::shuffle(){
    Card** s = new Card*[capacity];
	for(int i = 0; i < capacity; i++)
	{
        s[i] = deck.pop();
	}
    
    for(int i = 0; i < 2000; i++){
            int randx = rand() % 52;
            int randy = rand() % 52;
            Card* temp = s[randx];
            s[randx] = s[randy];
            s[randy] = temp;
    }
    for(int i = 0; i < capacity; i++){
            deck.push(s[i]);
    }
}
void Deck::createDeck(){
    int j = 0; int k = 0;
     for(int i = 0; i < capacity; i++){
        if(k == 13) k = 0;
        if(j == 4 ) j = 0;
        Card* c = new Card(j,k);
        deck.push(c);
        remainingCards++;
        j++;
        k++;
    }
}

Card* Deck::deal() {
    remainingCards--;
    return deck.pop();
}

bool Deck::isFull(){
    return remainingCards == 0;
}

const std::ostream& operator<<(std::ostream& os, Deck& d){
    os << d.deck;
    return os;
}