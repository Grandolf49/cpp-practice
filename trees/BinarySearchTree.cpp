//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "iostream"
#include "BinarySearchTree.h"

using namespace std;

TreeNode *BinarySearchTree::insertNode(int value) {
    if (this->head == nullptr) {
        this->head = new TreeNode(value);
    } else {

    }
    return head;
}

TreeNode *BinarySearchTree::removeNode(int value) {
    return nullptr;
}

TreeNode *BinarySearchTree::findNode(int value) {
    return nullptr;
}

int BinarySearchTree::getHeight() {
    return 0;
}

int BinarySearchTree::getSize() {
    return 0;
}

void BinarySearchTree::runner() {
    cout << "============= Binary Search Tree ===============" << endl;

}
