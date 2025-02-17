/**
 * @file twoSum.cpp
 * @brief Optimized O(n) Implementation of the Two Sum Problem.
 * 
 * This file contains an optimized solution for the Two Sum problem using an 
 * unordered_map for a single pass through the array.
 * Given an array of integers and a target integer, the function returns indices of 
 * the two numbers such that they add up to the target. This implementation assumes 
 * that each input has exactly one solution and that the same element is not used twice.
 * 
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * 
 * The algorithm uses an unordered_map to store each number and its index as you 
 * iterate through the array, achieving O(n) time complexity.
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // n represents the size of the vector.
        uint16_t n = nums.size();
        uint16_t i;
        int complement;
        unordered_map<int, uint16_t> map;
        auto it = map.end();

        // Insert the first number with its index into the map.
        map[nums[0]] = 0;

        // Iterate through the array starting from index 1.
        for(i = 1; i < n; i++){
            // Calculate the complement required to reach the target.
            complement = target - nums[i];
            // Check if the complement exists in the map.
            it = map.find(complement);
            if (it != map.end()){
                // If found, return the current index and the index of the complement.
                return {i, it->second}; 
            } else {
                // Otherwise, add the current number and its index to the map.
                map[nums[i]] = i;
            }
        }

        // Return {-1, -1} if no valid pair is found (should not happen per problem constraints).
        return {-1, -1};  
    }
};

int main() {
    // Example input: Change these values to test other cases.
    vector<int> nums = {2, 7, 11, 15};
    int target = 17;

    // Create a Solution object and call the twoSum function.
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    // Output the result.
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
