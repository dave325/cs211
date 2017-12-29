#ifndef GO_FISH_H
#define GO_FISH_H

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

class GoFish{
    private:
        bool winner;
        int* check;
        int size;
        int curr;
        int currPlayer;
        Player* p;
        Deck d;
        void initGame();
        bool calcWinner();
        void playerTurn();
        void dealerTurn();
        void dealCard();
        void addPlayer();
        void addPlayer(Player p1);
        Player getPlayer(int i);
        Player* getAllPlayers();
        bool getWinner();
        void resetCounter();
    public:
        GoFish();
        void play();
};

#endif