/**
 * @file longestCommonPrefix.cpp
 * @brief Longest Common Prefix Finder
 * 
 * This file implements a solution to find the longest common prefix among an array of strings.
 * The algorithm compares characters in each word until a mismatch is found.
 * 
 * ## Problem Statement:
 * Given an array of strings, return the longest common prefix string amongst them.
 * If there is no common prefix, return an empty string "".
 * 
 * ## Example:
 * **Input:** ["flower", "flow", "flight"]
 * **Output:** "fl"
 * 
 * **Input:** ["dog", "racecar", "car"]
 * **Output:** ""
 * 
 * **Constraints:**
 * - 1 <= strs.length <= 200
 * - 0 <= strs[i].length <= 200
 * - strs[i] consists of only lowercase English letters.
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            size_t word, car;
            string sout = "";
            uint8_t nbStr = strs.size();
            
            if (nbStr == 1){
                return strs[0];
            }

            car = 0;
            word = 1;
            while (word < nbStr){
                if (strs[0][car] != '\0' && strs[word][car] != '\0'
                    && strs[0][car] == strs[word][car]){
                    if (word == nbStr - 1){
                        sout += strs[0][car];
                        car++;
                        word = 1;
                    } else {
                        word++;
                    }
                } else {
                    break;
                }
            }
            return sout;
        }
};


/**
 * @brief Main function to test the longestCommonPrefix function
 */
int main() {
    Solution solution;
    vector<string> words1 = {"flower", "flow", "flight"};
    vector<string> words2 = {"dog", "racecar", "car"};
    vector<string> words3 = {"apple", "app", "apricot"};

    cout << "Test 1: " << solution.longestCommonPrefix(words1) << endl; // Expected: "fl"
    cout << "Test 2: " << solution.longestCommonPrefix(words2) << endl; // Expected: ""
    cout << "Test 3: " << solution.longestCommonPrefix(words3) << endl; // Expected: "ap"

    return 0;
}
 