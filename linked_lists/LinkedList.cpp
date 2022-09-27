//
// Created by Chinmay Kulkarni on 9/25/22.
//
#include "iostream"
#include "LinkedList.h"

using namespace std;

Node *LinkedList::create_node(Node *head, int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    return head;
}

void LinkedList::display(Node *head) {
    Node *temp = head;

    if (head == nullptr) {
        cout << "No linked list to display!" << endl;
        return;
    }

    cout << "Following is a snapshot of the current linked list:" << endl;
    while (temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

Node *LinkedList::update_node(Node *head, int old_value, int new_value) {
    return nullptr;
}

Node *LinkedList::delete_node(Node *head, int value) {
    // Find the node to dele
    return nullptr;
}

Node *LinkedList::reverse_list(Node *head) {
    return nullptr;
}