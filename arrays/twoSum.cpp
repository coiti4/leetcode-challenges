/**
 * @file twoSum.cpp
 * @brief Naive Implementation of the Two Sum Problem.
 * 
 * This file contains a naive solution for the Two Sum problem using a brute-force approach.
 * Given an array of integers and a target integer, the function returns indices of the two 
 * numbers such that they add up to the target. This implementation assumes that each input 
 * has exactly one solution and that the same element is not used twice.
 * 
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * 
 * Note: This naive approach uses nested iteration (with a while loop and resetting indices)
 * to examine all pairs until the correct pair is found.
 * 
 * @author Agustín Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // n represents the size of the vector.
        uint16_t n = nums.size();
        uint16_t i = 0;
        uint16_t j = 1;
        
        // Loop until the sum of the pair equals the target.
        while (nums[i] + nums[j] != target) {
            j++;
            // If j reaches the end of the array, increment i and reset j to i + 1.
            if (j == n) {
                i++;
                j = i + 1;
            }
        }
        
        // Return the indices as a vector.
        return {i, j};       
    }
};

int main() {
    // Example input: Change these values to test other cases.
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    // Create a Solution object and call the twoSum function.
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    
    // Output the result.
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
