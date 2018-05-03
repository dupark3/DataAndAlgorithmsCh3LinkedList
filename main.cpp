// Singly Linked List

#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList<int> my_list;
    my_list.insert_at_end(6);
    my_list.insert_at_end(7);
    my_list.insert_at_end(2);
    my_list.insert_at_end(7);
    my_list.insert_at_end(2);
    my_list.insert_at_end(2);
    my_list.insert_at_front(5);
    my_list.insert_at_front(2);
    my_list.insert_at_front(2);
    my_list.insert_at_front(2);
    my_list.print(); // 2 2 2 5 6 7 2 7 2 2
    my_list.delete_at_front();
    my_list.print(); // 2 2 5 6 7 2 7 2 2
    my_list.delete_at_end(); 
    my_list.print(); // 2 2 5 6 7 2 7 2
    my_list.delete_nodes(2);
    my_list.print(); // 5 6 7 7 
    
    return 0;
}