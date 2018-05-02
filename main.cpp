// Singly Linked List

#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList<int> my_list;
    my_list.insert_at_end(6);
    my_list.insert_at_end(7);
    my_list.insert_at_front(5);
    my_list.insert_at_front(4);
    my_list.print(); // 4 5 6 7
    my_list.delete_at_front();
    my_list.print(); // 5 6 7
    my_list.delete_at_end();
    my_list.delete_at_end();
    cout << "Deleting value: " << my_list.delete_at_end() << endl; // deleting last element
    my_list.print(); 
    cout << "Deleting value: " << my_list.delete_at_end() << endl; // trying to delete an empty list

    return 0;
}