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
    currPlayer = 1;
}

void BlackJack::playerTurn(){
    char ans;
    while(ans != 'S'){
        std::cout << "Current Player " << (currPlayer+1) << ": " << p[currPlayer].getName() << "\ntotal: " << p[currPlayer].evaluateHand() << "\n";
        p[currPlayer].display();
        std::cout << "\n";
        std::cout << "Current Player " << (currPlayer+1) << "\nWould you like to hit or hold? Press h for hit and s for hold.\n"; 
        std::cin >> ans;
        ans = toupper(ans);
        if(ans == 'H' && !check[currPlayer]){
            dealCard();
            if(calcWinner()){
                std::cout << "Player " << (currPlayer+1) << " wins!\n";
                return;
            }

            if(p[currPlayer].evaluateHand() > 21){
                std::cout << "Bust!\n\n";
                check[currPlayer] = true;
                break;
            }
        }else{
            break;
        }
    }
    resetCounter();
}

void BlackJack::dealerTurn(){
    std::cout << "Current Player "  << p[currPlayer].getName() << "\ntotal: " << p[currPlayer].evaluateHand() << "\n";
    p[currPlayer].display();
    std::cout << "\n";
    if(currPlayer == 0 && !check[currPlayer]){
        while(p[currPlayer].evaluateHand() < 17){
            dealCard();
        }
        check[currPlayer] = true;
        std::cout << "Current Player "  << p[currPlayer].getName() << "\ntotal: " << p[currPlayer].evaluateHand() << "\n";
        p[currPlayer].display();
        std::cout << "\n";
        if(calcWinner()){
            for(int i = 1; i < size; i++){
                if(p[i].evaluateHand() == p[0].evaluateHand()){
                    std::cout << "Tie!\n";
                    return;
                }
            }
        }
        if(p[currPlayer].evaluateHand() < 21){
            for(int i = 1; i < size; i++){
                if(p[i].evaluateHand() > p[0].evaluateHand()){
                    std::cout << "Player " << (i+1) << " wins!\n";
                }
                if(p[i].evaluateHand() == p[0].evaluateHand()){
                    std::cout << "Player " << (i+1) << " pushes!\n";
                }
                if(p[i].evaluateHand() < p[0].evaluateHand()){
                    std::cout << "Player " << (i+1) << " loses!\n";
                }           
            }
        }else{
            std::cout << "Dealer Busts!\n";
            for(int i = 1; i < size; i++){
                if(p[i].evaluateHand() < p[0].evaluateHand() && p[i].evaluateHand() < 21){
                    std::cout << "Player " << (i+1) << " wins!\n";
                }    
            }
        }       
         return;
    }
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
     int i = 0;
     while(!winner){
        if(currPlayer == 0){
            break;
        }
        playerTurn();
     }
     if(winner){
         return;
     }
     dealerTurn();
 }