#ifndef GUARD_LinkedList_h
#define GUARD_LinkedList_h

#include <climits> // INT_MIN
#include <iostream>

/*
TODO:
    Need insert/delete at random points
    Better encapsulation and protection of data
*/ 

template <class T>
class Node{
public:
    T value;
    Node<T> *next;
    Node<T> *previous;
    Node() : next(0), previous(0) { }
    Node(T val) : value(val), next(0), previous(0) { }
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
    void insert_at_front(T val);
    T delete_at_end();
    T delete_at_front();
    void delete_nodes(T);

    bool is_empty() { return head == 0; }
    void print();

    Node<T>* head;
    Node<T>* tail;
};

template <class T>
LinkedList<T>::~LinkedList(){
    if (!is_empty()){
        Node<T>* temp = head;
        while (temp->next){
            delete head;
            head = temp = temp->next;
        }
        delete temp;
    }
}

template <class T>
void LinkedList<T>::insert_at_end(T val){
    if (is_empty()){
        head = tail = new Node<int>(val);
    } else {
        tail->next = new Node<int>(val);
        tail->next->previous = tail;
        tail = tail->next;
    }
}

template <class T>
void LinkedList<T>::insert_at_front(T val){
    if (is_empty()){
        head = tail = new Node<int>(val);
    } else {
        head->previous = new Node<int>(val);
        head->previous->next = head;
        head = head->previous;
    }
}

// returns INT_MIN if trying to delete from an empty list
template <class T>
T LinkedList<T>::delete_at_end(){
    T value = INT_MIN;
    if (tail){
        value = tail->value;
        Node<T>* temp = tail;
        tail = tail->previous;
        if (tail) tail->next = 0;
        else head = tail = 0;
        delete temp;
    }
    return value;
}

// returns INT_MIN if trying to delete from an empty list
template <class T>
T LinkedList<T>::delete_at_front(){
    T value = INT_MIN;
    if(head){
        value = head->value;
        Node<T>* temp = head;
        head = head->next;
        head->previous = 0;
        delete temp;
    }
    return value;
}

template <class T>
void LinkedList<T>::delete_nodes(T value){
    if (is_empty())
        return;

    Node<T>* temp = head;
    
    // check value at head or the new head
    while (temp == head && temp->value == value){ 
        head = head->next;
        head->previous = 0;
        delete temp;
        temp = head;
    }
    
    // check in the middle of the list
    while(temp && temp != tail){ 
        if (temp->value == value) {
            Node<T>* temp2 = temp;
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            temp = temp->next;
            delete temp2;
        } else {
            temp = temp->next;
        }
    }

    // check tail of the list
    if (temp == tail && temp->value == value){
        tail = tail->previous;
        tail->next = 0;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::print(){
    if(!is_empty()){
        Node<T>* temp = head;
        do{
            std::cout << temp->value << " ";
        } while(temp = temp->next);
        std::cout << std::endl;
    } else {
        std:: cout << "Linked List is empty" << std::endl;
    }
}

#endif