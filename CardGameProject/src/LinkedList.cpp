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
	LinkedList(const LinkedList& l);
	~LinkedList();
	int getCount();
	void grow();
	void shrink();
	void insertAtIndex(int index, T * data);
	void remove(T& data);
	T * removeAtIndex(int index);
	int search(T * data);
	LinkedList<T>::Node* operator[](int i);	
	const LinkedList& operator=(LinkedList& other);
	friend const std::ostream& operator<<(std::ostream& os, LinkedList<T> l){
        for(int i = 0; i < l.size; i++){
            os << *(l[i]->data);
        }
        return os;
    }
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
LinkedList<T>::~LinkedList(){
    Node* n = head;
    for(int i = 0; i < size;i++){
        delete n;
        n = n->next;
    }
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
        Node* temp = head;
        head = new Node(data, head);
        head->next = temp;
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
    Node* newNode = new Node(data);
    if(index > size || index < 0){
        std::cerr << "Index does not exist";
        return;
    }

    if(isEmpty() || index == 0){
        insertAtHead(data);
        return;
    }

    if(index == size){
        insertAtTail(data);
        return;
    }
    for(int i = 0; i < index - 1; i++){
        n = n->next;
    }
    size++;
    Node* temp = n->next;
    n->next = newNode;
    newNode->next = temp;
    temp->next = newNode;
    return;
}

template <typename T>
void LinkedList<T>::remove(T& data){
    Node* n = head;    
    int i = 0;
    while(n != data){
        i++;
        n = n->next;
    }
    removeAtIndex(i);
}

template <typename T>
T* LinkedList<T>::removeAtIndex(int index){
    Node* n = head;
    int i = 0;
    while(n != NULL || index > size){
        if(i == index){
            n = n->next;
            size--;
            return n->data;
        }
        i++;
        n = n->next;
    }
    return n->data;
}

template <typename T>
int LinkedList<T>::search(T* data){
     Node* n = head;    
    int i = 0;
    while(n != data){
        i++;
        n = n->next;
    }
    if(n == NULL){
        return -1;
    }
    return i;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::operator[](int i){
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

#endif