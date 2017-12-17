#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "BlackJack.h"

BlackJack::BlackJack(){
    winner = false;
    curr = 0;
    currPlayer = 0;
    size = 1;
    initGame();
    d = Deck();
}

void BlackJack::dealCard(){
    p[currPlayer].addCard(d.deal());
}

void BlackJack::addPlayer(){
    if(curr == size){
        return;
    }
    std::string name;
    std::cout << "Please include the name of the player " << curr << "?" <<std::endl;
    std::cin >> name;
    Player newPlayer(name);
    this->p[curr] = newPlayer;
    curr++;
}

void BlackJack::addPlayer(Player p1){
    if(curr == size){
        return;
    }
    this->p[curr] = p1;
    curr++;
}

void BlackJack::initGame(){
    std::cout << "How many players?" <<std::endl;
    std::cin >> size;
    p = new Player[size];
    check = new bool[size];
    for(int i = 0; i < size; i++){
        if (i == 0){
            Player dealer("Dealer");
            addPlayer(dealer);
        }
        if(i > 0){
            addPlayer();
        }
        dealCard();
        dealCard();
        check[i] = false;
        resetCounter();
    }

}

void BlackJack::playerTurn(){
    std::cout << "Current Player " << (currPlayer+1) << ": " << p[currPlayer].getName() << "\ntotal: " << p[currPlayer].evaluateHand() << "\n";
    p[currPlayer].display();
    std::cout << "\n";
    if(currPlayer == 0 && !check[currPlayer]){
        if(p[currPlayer].evaluateHand() < 17){
            dealCard();
            if(calcWinner()){
                 std::cout << "Player " << (currPlayer+1) << " wins!\n";
                 return;
            }
        }else{
            check[currPlayer] = true;
        }
        resetCounter();
        return;
    }
    if(p[currPlayer].evaluateHand() > 21){
         check[currPlayer] = true;
         resetCounter();
         return;
     }
    char ans;
    std::cout << "Current Player " << (currPlayer+1) << "\nWould you like to hit or hold? Press h for hit and s for hold.\n"; 
    std::cin >> ans;
    ans = toupper(ans);
    if(ans == 'H' && !check[currPlayer]){
        dealCard();
    }else{
        check[currPlayer] = true;
    }

    if(calcWinner()){
        std::cout << "Player " << (currPlayer+1) << " wins!\n";
        return;
    }
    resetCounter();
}

Player BlackJack::getPlayer(int i){
    return p[i];
}

 Player* BlackJack::getAllPlayers(){
    return p;
 }

 bool BlackJack::getWinner(){
     return winner;
 }

 bool BlackJack::calcWinner(){
     for(int i = 0; i < size; i++){
         if(check[i] == false){
             break;
         }
         if(i == size-1){
             std::cout << "Draw\n" ;
             winner = true;
             return true;
         }
     }
     if(p[currPlayer].evaluateHand() == 21){
         p[currPlayer].display();
         winner = true;
         return true;
     }
     return false;
 }

void BlackJack::resetCounter(){
    if(currPlayer == (size - 1)){
        currPlayer = 0;
        return;
    }
    currPlayer++;
}

 void BlackJack::play(){
     while(!winner){
        playerTurn();
     }
 }