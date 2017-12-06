#include "Hand.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
Hand::Hand(){
    hand = new LinkedList();
}

LinkedList Hand::getHand(){
    return hand;
}

int Hand::countRank(int rank){
    
}

int Hand::evaluate(){

}

Card* Hand::getCardAt(int index){
    for(int i = 0; i < getCount(); i++){
        if(i == index){
            return hand[i];
        }
    }
    return NULL;
}
int Hand::getCount(){
    return hand.getCount();
}

bool Hand::hasRank(int rank){

}

void Hand::insertByRank(Card* card){

}

bool Hand::isEmpty(){
    return getCount() == 0;
}

std::string Hand::display(){
    for(int i = 0; i < getCount(); i++){
        std::cout << hand[i];
    }
}