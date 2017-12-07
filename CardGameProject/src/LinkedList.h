#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Card.h"

template <typename T>
class LinkedList {
public:
	class Node {
	public:
		T * data;
		Node * next;
		Node();
		Node(T * data);
		Node(T * data, Node * next);
	};
private:
	Node * head;
	Node * tail;
	int size;
	bool isEmpty();
	void insertAtHead(T * data);
	void insertAtTail(T * data);
	T * removeAtHead();
	T * removeAtTail();
public:
	LinkedList();
	//LinkedList(const LinkedList& l);
	//~LinkedList();
	int getCount();
	void grow();
	void shrink();
	void insertAtIndex(int index, T * data);
	void remove(T& data);
	T * removeAtIndex(int index);
	int search(T * data);
	LinkedList::Node* operator[](int i);	
	const LinkedList& operator=(LinkedList& other);
	friend const std::ostream& operator<<(std::ostream& os, LinkedList l);
};


template <typename T>
LinkedList<T>::Node::Node(){
    data = NULL;
    next = NULL;
}

template <typename T>
LinkedList<T>::Node::Node(T* data){
    this->data = data;
    this->next = NULL;
}

template <typename T>
LinkedList<T>::Node::Node(T* data, Node* next){
    this->data = data;
    this->next = next;
}

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template <typename T>
void LinkedList<T>::insertAtHead(T* data){
    if(isEmpty()){
        Node* n = new Node(data);
        head = n;
        tail = head;
    }else{
        head = new Node(data, head);
    }
    size++;
}

template <typename T>
void LinkedList<T>::insertAtTail(T* data){
    if(isEmpty()){
        insertAtHead(data);
        return;
    }else{
        tail->next = new Node(data);
        tail = tail->next;
    }
    size++;
}

template <typename T>
int LinkedList<T>::getCount(){
    return size;
}

template <typename T>
void LinkedList<T>::insertAtIndex(int index, T* data){
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

template <typename T>
void LinkedList<T>::remove(T& data){
    Node* n = head;    
}

template <typename T>
T* LinkedList<T>::removeAtIndex(int index){
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

template <typename T>
int LinkedList<T>::search(T* data){
    return 0;
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::operator[](int i){
    if(i < 0 || i > size){
        std::cerr << "Index does not exist!";
        exit(0);
    }
    Node* n = head;
    if(i == size){
        return n;
    }
    int j = 0;
}
#endif