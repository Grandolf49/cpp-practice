//
// Created by Chinmay Kulkarni on 10/4/22.
//
#include "iostream"
#include "unordered_map"

using namespace std;

#ifndef PRACTICE_DISJOINTSETS_H
#define PRACTICE_DISJOINTSETS_H

namespace disjoint_sets {

    class DisjointSets {
    private:
        const int SELF_PARENT = -1;
        unordered_map<int, int> parentMap;

        /**
         * This function will set parentN as the parent of parentM
         * @param parentN
         * @param parentM
         */
        void attachParents(int parentN, int parentM);

    public:
        void performUnion(int n, int m);

        int findParent(int n);

        void addNewElement(int n);

        void displayParents();
    };

    void runner();
}


#endif //PRACTICE_DISJOINTSETS_H
