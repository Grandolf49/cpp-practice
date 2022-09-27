//
// Created by Chinmay Kulkarni on 9/25/22.
//
#include "iostream"
#include "../helpers.h"

using namespace std;

#ifndef PRACTICE_INSERTIONSORT_H
#define PRACTICE_INSERTIONSORT_H


class InsertionSort {
private:
    int len;
    int *array;

public:
    InsertionSort(int len, int array[]) {
        this->len = len;
        this->array = array;
    }

    void print() {
        cout << "The sorted array is: " << endl;
        for (int i = 0; i < len; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void sort() {
        for (int i = 0; i < len - 1; i++) {
            // If current element is greater than next element
            if (array[i] > array[i + 1]) {
                // Move the next element into it's appropriate position
                // in the array traversed till now
                for (int j = i + 1; j > 0; j--) {
                    // If current element is smaller than previous element
                    if (array[j] < array[j - 1]) {
                        // Swap the 2 elements
                        swap(&len, &len);
                    } else {
                        // The element has reached its appropriate position
                        break;
                    }
                }
            }
        }
    }
};


#endif //PRACTICE_INSERTIONSORT_H
