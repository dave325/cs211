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
        void initGame();
        bool calcWinner();
        void playerTurn();
        void dealerTurn();
    public:
        BlackJack();
        void dealCard();
        void addPlayer();
        void addPlayer(Player p1);
        Player getPlayer(int i);
        Player* getAllPlayers();
        bool getWinner();
        void play();
        void resetCounter();
};

#endif