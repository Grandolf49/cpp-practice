//
// Created by Chinmay Kulkarni on 9/25/22.
//

#ifndef PRACTICE_LINKEDLIST_H
#define PRACTICE_LINKEDLIST_H

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() = default;

    Node *create_node(Node *head, int value);

    /**
     * Deletes the node with the first occurrence of value if exists
     * @param head
     * @param value
     * @return
     */
    Node *delete_node(Node *head, int value);

    /**
     * Updates the node with the first occurrence of old_value to new_value
     * @param head
     * @param old_value
     * @param new_value
     * @return
     */
    Node *update_node(Node *head, int old_value, int new_value);

    /**
     * Displays the current list
     */
    void display(Node *head);

    /**
     * Reverses the linked list and returns a pointer to the head of the list
     * @param head
     * @return
     */
    Node *reverse_list(Node *head);

    /**
     * Provide an implementation of a runner function for the user to understand
     * how to use the class
     */
    void runner();
};

#endif //PRACTICE_LINKEDLIST_H
