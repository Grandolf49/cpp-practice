//
// Created by Chinmay Kulkarni on 10/4/22.
//

#include "DisjointSets.h"

using namespace disjoint_sets;

int DisjointSets::findParent(int n) {
    if (this->parentMap.find(n) != this->parentMap.end()) {
        int parentOfN = this->parentMap[n];
        if (parentOfN < 0) {
            // Parent found
            return n;
        }
        // Connecting the child directly to it's parent to avoid
        // subsequent recursive calls
        this->parentMap[n] = findParent(parentOfN);
        return this->parentMap[n];
    }
    return NULL;
}

void DisjointSets::attachParents(int parentN, int parentM) {
    if (parentN != parentM) {
        // Get weights to update later
        int weightOfN = abs(this->parentMap[parentN]);
        int weightOfM = abs(this->parentMap[parentM]);

        // Set parentN as the parent of parentM
        this->parentMap[parentM] = parentN;
        // Update weight of parent of N
        this->parentMap[parentN] = -1 * (weightOfM + weightOfN);
    } else {
        cout << "Parent1 " << parentN << " and Parent2" << parentM << " are same." << endl;
    }
}

void DisjointSets::performUnion(int n, int m) {
    int parentOfN = findParent(n);
    cout << "parent of " << n << " is " << parentOfN << endl;
    int parentOfM = findParent(m);
    cout << "parent of " << m << " is " << parentOfM << endl;

    if (parentOfN != parentOfM) {
        int weightOfN = abs(this->parentMap[parentOfN]);
        cout << "weight of parent of " << n << " is " << weightOfN << endl;
        int weightOfM = abs(this->parentMap[parentOfM]);
        cout << "weight of parent of " << m << " is " << weightOfM << endl;

        /**
         * TODO: Implement Path Compression to reduce Time Complexity of Find Operation to O(1)
         */
        if (weightOfN > weightOfM) {
            // Parent of N has more children. Set parent of M to parent N
            attachParents(parentOfN, parentOfM);
        } else {
            // Parent of M has more children. Set parent of N to parent M
            attachParents(parentOfM, parentOfN);
        }
    } else {
        cout << "Parent N " << parentOfN << " and Parent M " << parentOfM << " are same. Skipping Union!" << endl;
    }
}

void DisjointSets::addNewElement(int n) {
    if (this->parentMap.find(n) == this->parentMap.end()) {
        // Can add new element
        this->parentMap[n] = this->SELF_PARENT;
    } else {
        cout << "ERROR: The element " << n << " already exists!" << endl;
    }
}

void DisjointSets::displayParents() {
    cout << "Child\t" << "Parent" << endl;
    for (auto mapPair: this->parentMap) {
        cout << mapPair.first << "\t" << mapPair.second << endl;
    }
}

void displayOptions() {
    cout << "1. Add elements to the set" << endl;
    cout << "2. Find parent of element" << endl;
    cout << "3. Union 2 sets" << endl;
    cout << "4. Display all children and their parents" << endl;
    cout << "5. Exit" << endl;
}


void handleChoices(const int choice, DisjointSets &disjointSets) {
    int element, parent;
    switch (choice) {
        case 1:
            int n;
            cout << "Enter number of elements you want to add: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) {
                cin >> element;
                disjointSets.addNewElement(element);
            }
            break;
        case 2:
            cout << "Enter number: ";
            cin >> element;
            parent = disjointSets.findParent(element);
            cout << "parent ==> " << parent << endl;
            cout << "The parent of " << element << " is " << parent << endl;
            break;
        case 3:
            int num1, num2;
            cout << "Enter 2 numbers to perform union:";
            cin >> num1 >> num2;
            disjointSets.performUnion(num1, num2);
            cout << "Union performed. New parents are as follows:" << endl;
            disjointSets.displayParents();
            break;
        case 4:
            disjointSets.displayParents();
        default:
            break;
    }
}

void disjoint_sets::runner() {
    int choice = 0;
    DisjointSets disjointSets = DisjointSets();

    cout << "============ Disjoint Sets ============" << endl;

    do {
        displayOptions();

        cout << "Enter your choice: ";
        cin >> choice;
        handleChoices(choice, disjointSets);

    } while (choice >= 1 and choice <= 4);
}
