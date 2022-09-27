//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "iostream"
#include "unordered_map"
#include "Utils.h"

using namespace std;

void Utils::map_test() {
    unordered_map<char, int> map;

    map['a'] = 1;
    map['b'] = 2;
    map['c'] = 3;

    for (auto x: map) {
        cout << x.first << " " << x.second << endl;
    }
}