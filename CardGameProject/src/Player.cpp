#include "Hand.h"
#include "Player.h"
#include "Deck.h"
#include <string>

Player::Player(){
    name = "";
    hand = new Hand();
    points = 0;
}

Player::Player(std::string n){
    name = n;
    hand = new Hand();
    points = 0;
}

void Player::setName(std::string name){
    this->name = name;
}

std::string Player::getName(){
    return name;
}

void Player::setPoints(int i){
    points = i;
}

int Player::getPoints(){
    return points;
}

std::string Player::playerInfo(){
    std::cout << "Name: " << name << std::endl  
        << "Points: " << points << std::endl;
    
}
std::string Player::showHand(){
    hand->display();
}

bool Player::hasRank(int rank){
    return hand->hasRank(rank);
}

void Player::addCard(Card * card){
    hand->getHand()->insertAtIndex(hand->getCount(), card);
}

Card * Player::getCardAt(int index){
    return hand->getCardAt(index);
}

void Player::removeCardAt(int index){
    hand->removeCardAt(index);
}

int Player::evaluateHand(){
    return hand->evaluate();
}

int Player::getTotalCards(){
    return hand->getCount();
}

void Player::display(){
    if(getTotalCards() == 0){
        std::cout << "No cards in hand." <<std::endl;
        return;
    }
    hand->display();
}