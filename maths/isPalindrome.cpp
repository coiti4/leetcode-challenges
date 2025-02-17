/**
 * @file isPalindrome.cpp
 * @brief Palindrome Number Checker
 * 
 * This file implements a solution to determine whether an integer is a palindrome.
 * A number is considered a palindrome if it reads the same forwards and backwards.
 * Negative numbers are not considered palindromes.
 * 
 * ## Problem Statement:
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 * 
 * ## Example:
 * **Input:** x = 121  
 * **Output:** true  
 * **Explanation:** 121 reads the same from left to right and right to left.
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0)
            return false;
        
        // Array to store the digits of x (maximum 10 digits for a 32-bit integer)
        uint8_t digits[10];
        uint8_t numDigits = 0;
        
        // Extract digits from x and store them in the array
        while (x > 0 && numDigits < 10) {
            digits[numDigits++] = x % 10;
            x /= 10;
        }
        
        // Compare the digits symmetrically: first with last, second with second-last, etc.
        for (uint8_t j = 0; j < numDigits / 2; j++) {
            if (digits[j] != digits[numDigits - 1 - j])
                return false;
        }
        
        return true;
    }
};

int main() {
    // Test cases
    int testNumbers[] = {121, -121, 10, 12321, 0, 123454321};
    int testCount = sizeof(testNumbers) / sizeof(testNumbers[0]);

    Solution sol;
    
    for (int i = 0; i < testCount; i++) {
        int x = testNumbers[i];
        bool result = sol.isPalindrome(x);
        cout << "Number: " << x << " -> " 
            << (result ? "Is a palindrome" : "Is not a palindrome") << endl;
    }

    return 0;
}
 