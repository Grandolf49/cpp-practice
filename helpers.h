//
// Created by Chinmay Kulkarni on 9/25/22.
//
#include "iostream"

using namespace std;

#ifndef PRACTICE_HELPERS_H
#define PRACTICE_HELPERS_H

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void array_input(int len, int *array) {
    cout << "Enter " << len << " numbers:" << endl;
    for (int i = 0; i < len; i++) {
        int t;
        cin >> t;
        *(array + 1) = t;
    }
}

#endif //PRACTICE_HELPERS_H
