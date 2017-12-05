#include <string>
#include <iostream>
#include "Card.h"
#include "LinkedList.h"

LinkedList::Node::Node(){
    data = NULL;
    next = NULL;
}

LinkedList::Node::Node(Card* data){
    this->data = data;
    this->next = NULL;
}

LinkedList::Node::Node(Card* data, Node* next){
    this->data = data;
    this->next = next;
}

LinkedList::LinkedList(){
    this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

bool LinkedList::isEmpty(){
    return size == 0;
}

void LinkedList::insertAtHead(Card* data){
    if(isEmpty()){
        Node* n = new Node(data);
        head = n;
        tail = head;
    }else{
        head = new Node(data, head);
    }
    size++;
}

void LinkedList::insertAtTail(Card* data){
    if(isEmpty()){
        insertAtHead(data);
        return;
    }else{
        tail->next = new Node(data);
        tail = tail->next;
    }
    size++;
}

int LinkedList::getCount(){
    return size;
}

void LinkedList::insertAtIndex(int index, Card* data){
    Node* n = head;
    int i = 0;
    if(index > size || index < 0){
        std::cerr << "Index does not exist";
        return;
    }
    if(index == size){
        insertAtTail(data);
        return;
    }
    if(isEmpty()){
        insertAtHead(data);
        return;
    }
    while(n != NULL || size > index){
        if(i == index){
             Node* temp = n;
             n->data = data;
             n->next = temp;
             size++;
             return;
        }
        i++;
        n = n->next;
    }
}

void LinkedList::remove(Card& data){
    Node* n = head;
    
}

Card* LinkedList::removeAtIndex(int index){
    Node* n = head;
    int i = 0;
    while(n != NULL || index > size){
        if(i == index){
            Node* temp = n;
            delete n;
            n = NULL;
            n = temp->next;
            size--;
            return temp->data;
        }
        i++;
    }
    return n->data;
}

int LinkedList::search(Card* data){
    return 0;
}

LinkedList::Node* LinkedList::operator[](int i){
    if(i < 0 || i > size){
        std::cerr << "Index does not exist!";
        exit(0);
    }
    Node* n = head;
    if(i == size){
        return n;
    }
    int j = 0;
    while(j < i){
        n = n->next;
        j++;
    }
    return n;
}

const std::ostream& operator<<(std::ostream& os, LinkedList l){
    for(int i = 0; i < l.size; i++){
        os << *(l[i]->data);
    }
    return os;
}