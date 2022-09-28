//
// Created by Chinmay Kulkarni on 9/27/22.
//
#include "vector"
#include "unordered_map"
#include "iostream"
#include "LongestSubstringWithoutRepeatingCharacters.h"

using namespace std;

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(std::string s) {
    int i = 0, j = 0, result = 0;
    unordered_map<char, int> map;

    while (i < s.length() && j < s.length()) {
        auto element = map.find(s[j]);

        // If element at j is not present in the map
        if (element == map.end()) {
            // Consider this element in the substring
            map[s[j]] = j;
        } else {
            // This element repeated. Drop all the elements
            // till the previous occurrence of this element
            for (int drop_idx = i; i <= element->second; drop_idx++) {
                map.erase(s[i]);
            }
            // Add new element to map
            map[s[j]] = j;
        }
        j++;
        result = max(result, j - i);
    }

    return result;
}

void LongestSubstringWithoutRepeatingCharacters::runner() {
    vector<string> test_strings = {
            "abcabcbb",
            "bbbbb",
            "pwwkew",
            ""
    };

    for (int i = 0; i < test_strings.size(); i++) {
        cout << "TestCase " << i + 1 << ": " << test_strings.at(i) << endl;
        cout << lengthOfLongestSubstring(test_strings.at(i)) << endl;
    }
}