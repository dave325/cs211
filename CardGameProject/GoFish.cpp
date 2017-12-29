#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "GoFish.h"

GoFish::GoFish(){
    winner = false;
    curr = 0;
    currPlayer = 0;
    size = 2;
    p = new Player[size];
    check = new int[size];
    initGame();
    d = Deck();
}

void GoFish::dealCard(){
    p[currPlayer].addCard(d.deal());
}

void GoFish::addPlayer(){
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

void GoFish::addPlayer(Player p1){
    if(curr == size){
        return;
    }
    this->p[curr] = p1;
    curr++;
}

void GoFish::initGame(){
    for(int i = 0; i < size; i++){
        if (i == 0){
            Player dealer("Computer");
            addPlayer(dealer);
        }
        if(i > 0){
            addPlayer();
        }
        for(int j = 0; j < 7; j++){
            dealCard();
        }
        check[i] = 0;
        resetCounter();
    }
}

void GoFish::playerTurn(){
    int ans = -1;
    std::cout << "***************************************************************\n";
    std::cout << p[currPlayer].getName() << "[Book(s): " << check[currPlayer]<< "]\n";
    p[currPlayer].display();
    std::cout << "Computer, do you have any: "; 
    std::cin >> ans;
    while(ans > 13 && ans < 0){
        std::cout << "Computer, do you have any: "; 
        std::cin >> ans;
        if(ans > 13 && ans < 0){
            std::cout << "\nWrong input. Computer, do you have any: "; 
            std::cin >> ans;
        }
    }
    if(p[0].hasRank(ans)){
        std::cout << p[0].getName() << " says \"Yes!!\"\n";
        for(int i = p[0].getTotalCards() - 1; i >= 0;i--){
            if(p[0].getCardAt(i)->getRank() + 1 == ans){
                p[currPlayer].addCard(p[0].getCardAt(i));
                p[0].removeCardAt(i);
                i--;
            }
        }
    }else{
        std::cout << "Computer says \"No Go Fish!!\"\n";
        dealCard();
    }
    ans = -1;
    calcWinner();
    std::cout << p[currPlayer].getName() << "[Book(s): " << check[currPlayer]<< "]\n";
    p[currPlayer].display();
    resetCounter();
}

void GoFish::dealerTurn(){
    std::cout << "***************************************************************\n";
    std::cout << "Computer [Book(s): " << check[currPlayer]<< "]\n";
    p[currPlayer].display();
    int rankNum = rand() % 13;
    while(!p[currPlayer].hasRank(rankNum)){
        rankNum = rand() % 13;
    }
    std::cout << p[1].getName() << ", do you have any: " << rankNum << std::endl; 
    if(p[1].hasRank(rankNum)){
        std::cout << p[1].getName() << " says \"Yes!!\"\n";
        for(int i = 0; i < p[1].getTotalCards();i++){
            if(p[1].getCardAt(i)->getRank() + 1 == rankNum){
                p[0].addCard(p[1].getCardAt(i));
                p[1].removeCardAt(i);
                i--;
            }
        }
    }else{
        std::cout << p[1].getName() << " says \"No Go Fish!!\"\n";
        dealCard();
    }
    calcWinner();
    std::cout << p[currPlayer].getName() << "[Book(s): " << check[currPlayer]<< "]\n";
    p[currPlayer].display();
    resetCounter();
}

Player GoFish::getPlayer(int i){
    return p[i];
}

 Player* GoFish::getAllPlayers(){
    return p;
 }

 bool GoFish::getWinner(){
     return winner;
 }

 bool GoFish::calcWinner(){
     int checkTotal = 0;
     for(int i = 0; i < 13; i++){
         checkTotal = 0;
         if(p[currPlayer].hasRank(i)){
            for(int k = 0; k < p[currPlayer].getTotalCards(); k++){
                if(p[currPlayer].getCardAt(k)->getRank() + 1 == i){
                    checkTotal++;
                }
            }
            if(checkTotal == 4){
                std::cout << "Book:[";
                for(int j = 0; j < p[currPlayer].getTotalCards(); j++){
                    if(p[currPlayer].getCardAt(j)->getRank() + 1 == i){
                        std::cout << " " << *p[currPlayer].getCardAt(j);
                        p[currPlayer].removeCardAt(j);
                    }
                }
                std::cout << "]\n";
                check[currPlayer]++;
            } // End of checkTotal if 
        } // End of for loop
     } // End of outer for loop
     if(p[currPlayer].getTotalCards() == 0){
         std::cout << p[currPlayer].getName() << " wins!\n";
         winner = true;
         return true;
     }
     return false;
 }

void GoFish::resetCounter(){
    if(currPlayer == (size - 1)){
        currPlayer = 0;
        return;
    }
    currPlayer++;
}

 void GoFish::play(){
     int i = 0;
     while(!winner){
        if(i == 5){
            break;
        }
        i++;
        dealerTurn();
        playerTurn();
     }
 }