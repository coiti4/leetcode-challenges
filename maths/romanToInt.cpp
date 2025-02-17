/**
 * @file romanToInt.cpp
 * @brief Converts Roman Numerals to Integers.
 * 
 * This file implements a solution for converting a Roman numeral string
 * into its integer representation. The conversion takes into account the
 * subtractive notation used in Roman numerals, such as:
 *   - IV (4) instead of IIII,
 *   - IX (9) instead of VIIII,
 *   - XL (40), XC (90), CD (400), and CM (900).
 * 
 * Roman numeral symbols and their corresponding values:
 *   I -> 1
 *   V -> 5
 *   X -> 10
 *   L -> 50
 *   C -> 100
 *   D -> 500
 *   M -> 1000
 * 
 * The algorithm scans the string from left to right and checks for cases
 * where a smaller numeral precedes a larger numeral (indicating subtraction).
 * If such a case is detected, it subtracts the smaller value from the larger
 * and adds the result to the total. Otherwise, it simply adds the numeral's value.
 * 
 * Example:
 *   Input: s = "MCMXCIV"
 *   Output: 1994
 * 
 * Constraints:
 *   - 1 <= s.length <= 15
 *   - s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *   - The input is a valid Roman numeral in the range [1, 3999].
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map to store Roman numeral symbols and their integer values.
        unordered_map<char, uint16_t> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        
        size_t i = 0;
        uint16_t converted = 0;
        
        // Process the string character by character.
        while (s[i] != '\0'){
            // If there is a next character and the current numeral is less than the next,
            // then it's a subtractive case (e.g., IV, IX, etc.)
            if (s[i+1] != '\0' && romanMap[s[i]] < romanMap[s[i+1]]){
                converted += romanMap[s[i+1]] - romanMap[s[i]];
                i += 2;
            } else {
                converted += romanMap[s[i]];
                i++;
            }
        }
        
        return converted;
    }
};

int main() {
    Solution sol;
    
    // Test cases for the romanToInt function.
    string testCases[] = {"III", "LVIII", "MCMXCIV"};
    int expected[] = {3, 58, 1994};
    
    for (size_t i = 0; i < 3; i++){
        int result = sol.romanToInt(testCases[i]);
        cout << "Roman numeral: " << testCases[i] 
            << " -> Integer: " << result 
            << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
