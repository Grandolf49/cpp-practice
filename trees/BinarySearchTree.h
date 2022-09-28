//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "iostream"

using namespace std;

#ifndef PRACTICE_SIMPLETREE_H
#define PRACTICE_SIMPLETREE_H

enum Traversal {
    BFS, PREORDER, INORDER, POSTORDER
};

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

namespace binary_search_tree {

    class BinarySearchTree {
    private:
        TreeNode *head = nullptr;

        TreeNode *insertNode(TreeNode *node, int value);

        void displayTreeBFS(TreeNode *node);

        void displayTreeInorder(TreeNode *node);

        void displayTreePreOrder(TreeNode *node);

        void displayTreePostOrder(TreeNode *node);

    public:
        TreeNode *insertNode(int value);

        TreeNode *removeNode(int value);

        TreeNode *findNode(int value);

        void displayTree(Traversal traversalMethod);

        int getHeight();

        int getSize();

    };

    void runner();
}

#endif //PRACTICE_SIMPLETREE_H
