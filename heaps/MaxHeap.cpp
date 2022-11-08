//
// Created by Chinmay Kulkarni on 11/8/22.
//

#include "MaxHeap.h"

using namespace std;
using namespace max_heap;

unsigned MaxHeap::size() {
    // Subtract 1 because 0 is the default element in the array
    return this->heapArray.size() - 1;
}

void MaxHeap::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void MaxHeap::heapifyDelete(unsigned idx_parent) {
    unsigned idx_left_child = 2 * idx_parent;
    unsigned idx_right_child = idx_left_child + 1;

    // If idx_parent is a leaf node, return
    if (idx_left_child >= this->size() || idx_right_child >= this->size())
        return;

    int parent = this->heapArray[idx_parent];
    // If idx_parent is not a leaf node, it will always have a left child
    int left_child = this->heapArray[idx_left_child];
    // If idx_parent is not a leaf node, it may or may not have a right child
    int right_child = idx_right_child >= this->size() ? INT_MIN : this->heapArray[idx_left_child];

    unsigned idx_max_child = idx_left_child;
    int max_child = left_child;
    if (right_child > left_child) {
        idx_max_child = idx_right_child;
        max_child = right_child;
    }

    // Compare parent with left and right children
    if (parent < max_child) {
        // Swap parent with max child
        swap(&this->heapArray[idx_parent], &this->heapArray[idx_max_child]);
        // Call heapifyDelete on max child to rearrange elements
        heapifyDelete(idx_max_child);
    }
}

void MaxHeap::heapifyInsert(unsigned idx_element) {
    if (idx_element == 1)
        // Root is always a valid heap
        return;

    // Compare idx_element with its parents
    unsigned idx_parent = idx_element / 2;
    if (this->heapArray[idx_parent] < this->heapArray[idx_element]) {
        // Swap idx_parent and idx_element
        swap(&this->heapArray[idx_parent], &this->heapArray[idx_element]);
        // Call heapifyInsert with idx_parent;
        heapifyInsert(idx_parent);
    }
}

void MaxHeap::insertElement(int n) {
    // Always insert element at the last position of the array
    this->heapArray.push_back(n);

    // Call heapifyInsert to rearrange elements to preserve
    this->heapifyInsert(this->size());
}

int MaxHeap::deleteElement() {
    if (this->heapArray.empty())
        return INT_MIN;

    // Return first element of the heap
    int element = this->heapArray[0];

    // Copy last element to the root
    this->heapArray[0] = this->heapArray.back();

    // Delete last element
    this->heapArray.pop_back();

    // Call heapifyDelete (top down) to rearrange elements
    heapifyDelete(0);

    return element;
}

void MaxHeap::printHeap() {
    cout << "Heap so far:\n";
    for (int i = 1; i <= this->size(); i++) {
        cout << this->heapArray[i] << " ";
    }
    cout << endl;
}

void max_heap::runner() {
    cout << "======== Max Heap ========\n";

    vector<int> elements = {
//            6, 3, 4, 8, 1, 9, 2, 7, 5
            1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    MaxHeap maxHeap = MaxHeap();

    cout << "======= Insertion ======\n";
    for (auto &i: elements) {
        cout << "Inserting " << i << " into max heap\n";
        maxHeap.insertElement(i);
        maxHeap.printHeap();
    }

//    cout << "======= Deletion ======\n";
//    for (int i = 0; i < maxHeap.size(); i++) {
//        cout << "Deleting " << i << "th element from max heap\n";
//        maxHeap.deleteElement();
//        maxHeap.printHeap();
//    }
}