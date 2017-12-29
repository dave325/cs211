#include "Hand.h"
#include "LinkedList.cpp"
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
    int count = 0;
    for(int i = 0; i < getCount(); i++){
        count += (*getCardAt(i)).getValue();
    }
    if(count > 21 && hasRank(0)){
        count -= 10;
    }
    return count;
}

Card* Hand::getCardAt(int index){
    if(index < 0 || index > getCount()){
        return NULL;
    }
    return (*hand)[index]->data;
}

void Hand::removeCardAt(int index){
    hand->removeAtIndex(index);
}

int Hand::getCount(){
    return (*hand).getCount();
}

bool Hand::hasRank(int rank){
    for(int i = 0; i < getCount(); i++){
        if(getCardAt(i)->getRank()+1 == (rank)){
            return true;
        }
    }
    return false;
}

void Hand::insertByRank(Card* card){
    if(getCount() == 0){
        hand->insertAtIndex(0,card);
        return;
    }
    for(int i = 0; i < getCount(); i++){
        if (i > 5 ){
            std::cout << "broke" << std::endl;
            break;
        }
        if(getCardAt(i)->getRank() >= card->getRank()){
            std::cout << "i: " << *card;
            (*hand).insertAtIndex(i,card);
            return;
        }
    }
     (*hand).insertAtIndex(getCount(),card);
}

bool Hand::isEmpty(){
    return getCount() == 0;
}

std::string Hand::display(){
    std::string s = "";
    for(int i = 0; i < getCount(); i++){
        std::cout << *getCardAt(i);
    }
    return s;
}