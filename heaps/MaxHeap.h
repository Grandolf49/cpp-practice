//
// Created by Chinmay Kulkarni on 11/8/22.
//
#include <iostream>
#include <vector>

#ifndef PRACTICE_MAXHEAP_H
#define PRACTICE_MAXHEAP_H

using namespace std;

namespace max_heap {

    class MaxHeap {

    private:
        vector<int> heapArray;

        void swap(int *a, int *b);

        void heapifyInsert(unsigned idx_element);

        void heapifyDelete(unsigned idx_parent);

    public:

        MaxHeap() {
            // To make this work with 1-indexed array
            this->heapArray.push_back(0);
        }

        unsigned size();

        int deleteElement();

        void insertElement(int n);

        void printHeap();
    };

    void runner();
}

#endif //PRACTICE_MAXHEAP_H
