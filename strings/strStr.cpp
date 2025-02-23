/**
 * @file strStr.cpp
 * @brief Implements strStr() to find the first occurrence of a substring in a string. Naive implementation O(m*n).
 *
 * This file contains a solution for LeetCode problem 28: Implement strStr().
 * The function takes two strings: 'haystack' (the string to search in) and 'needle'
 * (the substring to find). It returns the index of the first occurrence of 'needle'
 * in 'haystack', or -1 if 'needle' is not found. If 'needle' is an empty string,
 * the function should return 0.
 *
 * Example:
 *   Input: haystack = "hello", needle = "ll"
 *   Output: 2 (the substring "ll" starts at index 2)
 *
 *   Input: haystack = "aaaaa", needle = "bba"
 *   Output: -1 (the substring "bba" is not found)
 *
 * Constraints:
 *   - 0 <= haystack.length, needle.length <= 5 * 10^4
 *   - haystack and needle consist only of lowercase English characters.
 *
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) 
            return -1;

        uint16_t i = 0;  // index for needle
        uint16_t j = 0;  // index for haystack

        while (needle[i] != '\0') {
            if (needle[i] == haystack[j]) {
                i++;
                j++;
            } else {
                j = j - i + 1;  // go back j and advance one position
                i = 0;          // restore i
                if (haystack[j] == '\0')
                    return -1;
            }
        }

        return j - needle.size();  // return the initial index
    }
};

int main() {
    Solution solution;

    // Test case 1: Basic match
    std::string haystack1 = "hello";
    std::string needle1 = "ll";
    int expected1 = 2;
    int result1 = solution.strStr(haystack1, needle1);
    std::cout << "Test 1: haystack = \"" << haystack1 << "\", needle = \"" << needle1 
            << "\", expected = " << expected1 << ", result = " << result1 << std::endl;
    assert(result1 == expected1 && "Test 1 failed");

    // Test case 2: Needle not found
    std::string haystack2 = "aaaaa";
    std::string needle2 = "bba";
    int expected2 = -1;
    int result2 = solution.strStr(haystack2, needle2);
    std::cout << "Test 2: haystack = \"" << haystack2 << "\", needle = \"" << needle2 
            << "\", expected = " << expected2 << ", result = " << result2 << std::endl;
    assert(result2 == expected2 && "Test 2 failed");

    // Test case 3: Empty needle
    std::string haystack3 = "hello";
    std::string needle3 = "";
    int expected3 = 0;
    int result3 = solution.strStr(haystack3, needle3);
    std::cout << "Test 3: haystack = \"" << haystack3 << "\", needle = \"" << needle3 
            << "\", expected = " << expected3 << ", result = " << result3 << std::endl;
    assert(result3 == expected3 && "Test 3 failed");

    // Test case 4: Empty haystack, non-empty needle
    std::string haystack4 = "";
    std::string needle4 = "a";
    int expected4 = -1;
    int result4 = solution.strStr(haystack4, needle4);
    std::cout << "Test 4: haystack = \"" << haystack4 << "\", needle = \"" << needle4 
            << "\", expected = " << expected4 << ", result = " << result4 << std::endl;
    assert(result4 == expected4 && "Test 4 failed");

    // Test case 5: Needle at the end
    std::string haystack5 = "mississippi";
    std::string needle5 = "pi";
    int expected5 = 9;
    int result5 = solution.strStr(haystack5, needle5);
    std::cout << "Test 5: haystack = \"" << haystack5 << "\", needle = \"" << needle5 
            << "\", expected = " << expected5 << ", result = " << result5 << std::endl;
    assert(result5 == expected5 && "Test 5 failed");

    // Test case 6: Partial match with mismatch
    std::string haystack6 = "mississippi";
    std::string needle6 = "issip";
    int expected6 = 4;
    int result6 = solution.strStr(haystack6, needle6);
    std::cout << "Test 6: haystack = \"" << haystack6 << "\", needle = \"" << needle6 
            << "\", expected = " << expected6 << ", result = " << result6 << std::endl;
    assert(result6 == expected6 && "Test 6 failed");

    std::cout << "All test cases completed. Check output for failures." << std::endl;
    return 0;
}
