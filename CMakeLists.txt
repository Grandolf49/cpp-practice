cmake_minimum_required(VERSION 3.23)
project(Practice)

set(CMAKE_CXX_STANDARD 11)

add_executable(Practice main.cpp linked_lists/runner.cpp linked_lists/LinkedList.cpp linked_lists/LinkedList.h helpers.h sorting/InsertionSort.cpp sorting/InsertionSort.h utils/Utils.cpp utils/Utils.h leetcode/LongestSubstringWithoutRepeatingCharacters.cpp leetcode/LongestSubstringWithoutRepeatingCharacters.h trees/BinarySearchTree.cpp trees/BinarySearchTree.h disjoint_sets/DisjointSets.cpp disjoint_sets/DisjointSets.h leetcode/MinCostToConnectAllPoints.cpp heaps/MaxHeap.cpp heaps/MaxHeap.h)
