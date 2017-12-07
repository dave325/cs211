#include "Hand.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
Hand::Hand(){
    hand = new LinkedList<Card>();
}

LinkedList<Card>* Hand::getHand(){
    return hand;
}

int Hand::countRank(int rank){
    int count = 0;
    for(int i = 0; i < getCount(); i++){
        count += (*getCardAt(i)).getRank();
    }
    return count;
}

int Hand::evaluate(){
   
}

Card* Hand::getCardAt(int index){
    if(index < getCount() && index > getCount()){
        return NULL;
    }
    return (*hand)[index]->data;
}

int Hand::getCount(){
    return (*hand).getCount();
}

bool Hand::hasRank(int rank){
    for(int i = 0; i < getCount(); i++){
        if((*getCardAt(i)).getRank() == rank){
            return true;
        }
    }
    return false;
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