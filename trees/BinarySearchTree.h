//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "iostream"

using namespace std;

#ifndef PRACTICE_SIMPLETREE_H
#define PRACTICE_SIMPLETREE_H

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode *head = nullptr;
public:
    TreeNode *insertNode(int value);

    TreeNode *removeNode(int value);

    TreeNode *findNode(int value);

    int getHeight();

    int getSize();

    void runner();
};


#endif //PRACTICE_SIMPLETREE_H
