#ifndef GUARD_LinkedList_h
#define GUARD_LinkedList_h

// Singly Linked List
// forward declare LinkedList
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
    ~LinkedList() { delete head; delete tail; }
    
    LinkedList& operator= (const LinkedList& list);
    void insert(T val);

    Node<T>* head;
    Node<T>* tail;
};


template <class T>
void LinkedList<T>::insert(T val){
    if (!head)
        head = tail = new Node<int>(val);
    else {
        tail->next = new Node<int>(val);
        tail = tail->next;
    }
}


#endif
