//
// Created by Chinmay Kulkarni on 9/25/22.
//
#include <iostream>
#include "LinkedList.h"

using namespace std;

Node *head = nullptr;

void show_options() {
    cout << "===============Linked List Basic Program===============" << endl;
    cout << "1. Create/Add new node" << endl;
    cout << "2. View linked list" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Reverse current list" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter option number: ";
}

int read_option() {
    int choice;
    cin >> choice;
    return choice;
}

void create_add_new_node(LinkedList linkedList) {
    int val;
    cout << "Enter the value of the node: ";
    cin >> val;

    head = linkedList.create_node(head, val);

    cout << "Node with value " << val << " created!" << endl;
}

void view_linked_list(LinkedList linkedList) {
    linkedList.display(head);
}

void reverse_linked_list(LinkedList linkedList) {
    cout << "NOT IMPLEMENTED!" << endl;
}

void delete_node(LinkedList linkedList) {
    cout << "NOT IMPLEMENTED!" << endl;
}

bool handle_option(int option, LinkedList linkedList) {
    switch (option) {
        case 1:
            create_add_new_node(linkedList);
            break;
        case 2:
            view_linked_list(linkedList);
            break;
        case 3:
            delete_node(linkedList);
            break;
        case 4:
            reverse_linked_list(linkedList);
            break;
        default:
            return false;
    }
    return true;
}

void LinkedList::runner() {
    bool run_again;
    LinkedList linkedList;

    do {
        show_options();

        int option = read_option();

        run_again = handle_option(option, linkedList);

    } while (run_again);
}
