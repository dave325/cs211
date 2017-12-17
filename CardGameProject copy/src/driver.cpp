#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
int main(){
    Deck d;
    Hand h;
    Player p("David");
    h.insertByRank(d.deal());
    h.insertByRank(d.deal());
    h.insertByRank(d.deal());
    h.insertByRank(d.deal());
    h.insertByRank(d.deal());
    h.insertByRank(d.deal());
    for(int i = 0; i < h.getCount(); i++){
        std::cout << *h.getCardAt(i);
        p.addCard(h.getCardAt(i));
    }
    std::cout << "After initial show" <<std::endl;
    p.display();
    std::cout << p.evaluateHand();
    std::cout << "\nrank " << h.hasRank(1) << std::endl;
    std::cout << d.getRemainingCards() << std::endl;
    return 0;
}