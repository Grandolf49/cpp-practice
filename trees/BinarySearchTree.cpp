//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "iostream"
#include "vector"
#include "../helpers.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace binary_search_tree;

TreeNode *BinarySearchTree::insertNode(TreeNode *node, int value) {
    if (node == nullptr) {
        node = new TreeNode(value);
    } else {
        if (node->val > value) {
            // Insert into left side of the tree
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }
    }
    return node;
}

TreeNode *BinarySearchTree::insertNode(int value) {
    head = insertNode(this->head, value);
    return head;
}

TreeNode *BinarySearchTree::removeNode(int value) {
    throw NotImplementedError();
}

TreeNode *BinarySearchTree::findNode(int value) {
    throw NotImplementedError();
}

int BinarySearchTree::getHeight() {
    throw NotImplementedError();
}

int BinarySearchTree::getSize() {
    throw NotImplementedError();
}

void BinarySearchTree::displayTreeBFS(TreeNode *node) {

}

void BinarySearchTree::displayTreeInorder(TreeNode *node) {
    if (node != nullptr) {
        cout << node->val << " ";
        this->displayTreeInorder(node->left);
        this->displayTreeInorder(node->right);
    }
}

void BinarySearchTree::displayTreePreOrder(TreeNode *node) {

}

void BinarySearchTree::displayTreePostOrder(TreeNode *node) {

}

void BinarySearchTree::displayTree(Traversal traversalMethod) {
    switch (traversalMethod) {
        case Traversal::BFS:
            this->displayTreeBFS(this->head);
            break;
        case Traversal::INORDER:
            this->displayTreeInorder(this->head);
            break;
        case Traversal::PREORDER:
            this->displayTreePreOrder(this->head);
            break;
        case Traversal::POSTORDER:
            this->displayTreePostOrder(this->head);
            break;
    }
    cout << endl;
}

void binary_search_tree::runner() {
    cout << "============= Binary Search Tree ===============" << endl;

    vector<int> elements{5, 3, 7, 9, 2, 4, 1, 8};
    BinarySearchTree bst = BinarySearchTree();

    for (int value: elements) {
        cout << "Inserting " << value << " in BST" << endl;
        bst.insertNode(value);
    }

    cout << "The BST is:" << endl;
    bst.displayTree(Traversal::INORDER);
}
