/**
 * @file lengthOfLastWord.cpp
 * @brief Computes the length of the last word in a string.
 *
 * This file contains a solution for LeetCode problem 58: Length of Last Word.
 * The function takes a string 's' consisting of words and spaces and returns the
 * length of the last word in the string. A word is defined as a maximal substring
 * consisting of non-space characters only. The approach uses a single pass through
 * the string, tracking the current word length and the previous word length, with
 * a time complexity of O(n) and space complexity of O(1).
 *
 * Example:
 *   Input: s = "Hello World"
 *   Output: 5 (the last word "World" has length 5)
 *
 *   Input: s = "   fly me   to   the moon  "
 *   Output: 4 (the last word "moon" has length 4)
 *
 * Constraints:
 *   - 1 <= s.length <= 10^4
 *   - s consists of English letters and spaces only
 *
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

class Solution {
public:
    /**
     * @brief Returns the length of the last word in the input string.
     *
     * This function iterates through the string character by character, counting
     * the length of the current word (l) and storing the length of the previous
     * word (l_prev) when a space is encountered. At the end, it returns the current
     * word length if non-zero, or the previous word length if the string ends with spaces.
     *
     * @param s The input string containing words and spaces.
     * @return The length of the last word in the string.
     */
    int lengthOfLastWord(std::string s) {
        uint16_t i = 0;        // Index to traverse the string
        uint16_t l = 0;        // Length of the current word
        uint16_t l_prev = 0;   // Length of the previous word

        while (s[i] != '\0') {
            if (s[i] != ' ') {
                l++;           // Increment current word length
            } else {
                if (l) {       // If we had a word before this space
                    l_prev = l; // Store its length
                }
                l = 0;         // Reset current word length
            }
            i++;              // Move to next character
        }

        return l ? l : l_prev; // Return current length if non-zero, else previous
    }
};

int main() {
    Solution solution;

    // Test case 1: Basic two-word string
    std::string s1 = "Hello World";
    int expected1 = 5;
    int result1 = solution.lengthOfLastWord(s1);
    std::cout << "Test 1: s = \"" << s1 << "\", expected = " << expected1 
            << ", result = " << result1 << std::endl;
    assert(result1 == expected1 && "Test 1 failed");

    // Test case 2: String with trailing spaces
    std::string s2 = "   fly me   to   the moon  ";
    int expected2 = 4;
    int result2 = solution.lengthOfLastWord(s2);
    std::cout << "Test 2: s = \"" << s2 << "\", expected = " << expected2 
            << ", result = " << result2 << std::endl;
    assert(result2 == expected2 && "Test 2 failed");

    // Test case 3: Single word
    std::string s3 = "World";
    int expected3 = 5;
    int result3 = solution.lengthOfLastWord(s3);
    std::cout << "Test 3: s = \"" << s3 << "\", expected = " << expected3 
            << ", result = " << result3 << std::endl;
    assert(result3 == expected3 && "Test 3 failed");

    // Test case 4: Single word with leading spaces
    std::string s4 = "     Hello";
    int expected4 = 5;
    int result4 = solution.lengthOfLastWord(s4);
    std::cout << "Test 4: s = \"" << s4 << "\", expected = " << expected4 
            << ", result = " << result4 << std::endl;
    assert(result4 == expected4 && "Test 4 failed");

    // Test case 5: Multiple spaces between words
    std::string s5 = "a   b   c";
    int expected5 = 1;
    int result5 = solution.lengthOfLastWord(s5);
    std::cout << "Test 5: s = \"" << s5 << "\", expected = " << expected5 
            << ", result = " << result5 << std::endl;
    assert(result5 == expected5 && "Test 5 failed");

    // Test case 6: Single character with spaces
    std::string s6 = " a ";
    int expected6 = 1;
    int result6 = solution.lengthOfLastWord(s6);
    std::cout << "Test 6: s = \"" << s6 << "\", expected = " << expected6 
            << ", result = " << result6 << std::endl;
    assert(result6 == expected6 && "Test 6 failed");

    std::cout << "All test cases completed successfully!" << std::endl;
    return 0;
}
