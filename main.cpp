// Singly Linked List

#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList<int> my_list;
    my_list.insert_at_end(5);
    my_list.insert_at_end(6);
    my_list.insert_at_end(7);
    cout << my_list.head->value << endl;
    cout << my_list.head->next->value << endl;
    cout << my_list.tail->value<< endl;
    return 0;
}