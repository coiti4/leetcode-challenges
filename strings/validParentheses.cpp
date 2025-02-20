/**
 * @file validParentheses.cpp
 * @brief Valid Parentheses Checker
 * 
 * This file implements a solution to determine if a given string containing only
 * the characters '(', ')', '{', '}', '[' and ']' is valid.
 * 
 * A string is considered valid if:
 * - Open brackets are closed by the same type of brackets.
 * - Open brackets are closed in the correct order.
 * - Every close bracket has a corresponding open bracket of the same type.
 * 
 * ## Problem Statement:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * 
 * ## Examples:
 * **Example 1:**  
 * Input: s = "()"  
 * Output: true
 * 
 * **Example 2:**  
 * Input: s = "()[]{}"  
 * Output: true
 * 
 * **Example 3:**  
 * Input: s = "(]"  
 * Output: false
 * 
 * **Example 4:**  
 * Input: s = "([])"  
 * Output: true
 * 
 * ## Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only: '()[]{}'.
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

 #include <iostream>
 #include <stack>
 #include <string>
 #include <vector>
 #include <cstdint>
 
 using namespace std;
 
 class Solution {
 public:
     /**
      * @brief Checks if the given string of parentheses is valid.
      * 
      * @param s The input string containing the parentheses.
      * @return true if the string is valid, false otherwise.
      */
     bool isValid(string s) {
         uint16_t n = s.length();
 
         // If the number of characters is odd, the string cannot be valid.
         if (n % 2)
             return false;
 
         uint16_t i = 0;
         stack<char> brackets;
 
         while (i < n) {
             // If the character is an opening bracket, push it to the stack.
             if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                 brackets.push(s[i]);
             } else { // If a closing bracket is encountered.
                 if (!brackets.empty()) {
                     // Check valid pair using a switch statement.
                     switch (s[i]) {
                         case ')':
                             if (brackets.top() == '(')
                                 brackets.pop();
                             else
                                 return false;
                             break;
                         case ']':
                             if (brackets.top() == '[')
                                 brackets.pop();
                             else
                                 return false;
                             break;
                         case '}':
                             if (brackets.top() == '{')
                                 brackets.pop();
                             else
                                 return false;
                             break;
                         default:
                             break;
                     }
                 } else {
                     // No corresponding opening bracket.
                     return false;
                 }
             }
             i++;
         }
 
         // If the stack is empty, all brackets were properly matched.
         return brackets.empty();
     }
 };
 
 /**
  * @brief Main function to test the valid parentheses solution.
  */
 int main() {
     Solution solution;
     vector<string> testCases = {
         "()",
         "()[]{}",
         "(]",
         "([])",
         "({[]})",
         "([)]",    // Invalid
         "{[]}",
         "((("      // Invalid
     };
 
     for (const auto& test : testCases) {
         cout << "Input: \"" << test << "\" => Output: "
              << (solution.isValid(test) ? "true" : "false") << endl;
     }
 
     return 0;
 }
 