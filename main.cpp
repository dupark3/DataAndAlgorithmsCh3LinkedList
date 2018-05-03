// Singly Linked List

#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(){
    // default constructor called
    LinkedList<int> my_list;

    // inserting at the front and end
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
    
    // deleting at the head and tail and deleting all nodes with certain value
    my_list.delete_at_front();
    my_list.print(); // 2 2 5 6 7 2 7 2 2
    my_list.delete_at_end(); 
    my_list.print(); // 2 2 5 6 7 2 7 2
    my_list.delete_nodes(2);
    my_list.print(); // 5 6 7 7 
    
    // checking if an element exists in the list
    if (my_list.is_in_list(7))
        cout << "7 is in the list." << endl;
    if (!my_list.is_in_list(15))
        cout << "15 is not in the list. " << endl;

    // copy constructor makes deep copy
    LinkedList<int> new_list(my_list); 
    new_list.insert_at_front(10);
    cout << "new_list from copy constructor and inserting 10 at front: " << endl;
    new_list.print(); // 10 5 6 7 7
    cout << "my_list is unaffected by insertion at the new_list: " << endl;
    my_list.print(); // 5 6 7 7

    // size functions
    cout << "my_list size: " << my_list.size() << endl;
    cout << "new_list size: " << new_list.size() << endl;

    // inserting in the middle of the list
    new_list.insert_at_index(20, 2);
    new_list.print(); // 10 5 6 7 7

    return 0;
}