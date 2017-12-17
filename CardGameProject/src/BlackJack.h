#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

class BlackJack{
    private:
        bool winner;
        bool* check;
        int size;
        int curr;
        int currPlayer;
        Player* p;
        Deck d;
    public:
        BlackJack();
        void dealCard();
        void addPlayer();
        void addPlayer(Player p1);
        void initGame();
        void playerTurn();
        Player getPlayer(int i);
        Player* getAllPlayers();
        bool calcWinner();
        bool getWinner();
        void play();
        void resetCounter();
};

#endif