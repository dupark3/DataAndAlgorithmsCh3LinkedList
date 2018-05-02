#ifndef GUARD_LinkedList_h
#define GUARD_LinkedList_h

#include <iostream>

/*
TODO:
    Better encapsulation and protection of data
*/ 

template <class T>
class Node{
public:
    T value;
    Node<T> *next;
    Node() : next(0) { }
    Node(T val) : value(val), next(0) { }
};

template <class T>
class LinkedList{
public:
    LinkedList() : head(0), tail(0) { }
    LinkedList(T val) { head = tail = new Node<T>(val); }
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator= (const LinkedList&);
    
    void insert_at_end(T val);
    
    Node<T>* head;
    Node<T>* tail;
};

template <class T>
void LinkedList<T>::insert_at_end(T val){
    if (!head)
        head = tail = new Node<int>(val);
    else {
        tail->next = new Node<int>(val);
        tail = tail->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* temp = head;
    while (temp->next){
        delete head;
        head = temp = temp->next;
    }
    delete temp;
}

#endif