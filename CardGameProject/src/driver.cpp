#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Stack.h"
#include "Deck.h"
#include "LinkedList.h"
int main(){
    Deck d;
    LinkedList l;
    l.insertAtIndex(0,d.deal());
    l.insertAtIndex(1,d.deal());
    l.insertAtIndex(2,d.deal());
    std::cout << "After Deal" << std::endl;
    std::cout << l;
    std::cout << d.getRemainingCards();
    std::cout << *d.getDeck().peek();
    return 0;
}