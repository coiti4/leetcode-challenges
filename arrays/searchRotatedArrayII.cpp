/**
 * @file searchRotatedArray.cpp
 * @brief Naive Implementation: Search in a Rotated Sorted Array with Duplicates.
 * 
 * REVISIT LATER
 * 
 * This file contains a **naive solution** to search for a target value in a rotated sorted
 * array that may contain duplicates. The solution uses a simple linear search algorithm,
 * which does not take advantage of the sorted or rotated properties of the array.
 * 
 * Problem Statement:
 * Given an integer array `nums` sorted in non-decreasing order (and then rotated at an unknown
 * pivot) and an integer `target`, return true if `target` exists in `nums`, or false otherwise.
 * 
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Note: This is the naive implementation using a linear search, which has a worst-case time
 * complexity of O(n). More optimal solutions exist that leverage the properties of the rotated
 * sorted array, but this implementation serves as a simple baseline.
 * 
 * @author Agustín Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // n represents the effective size of the vector.
        uint16_t n = nums.size();
        uint16_t i = 0;
        
        // Traverse the entire vector.
        while (i < n) {
            if (nums[i] == target)
                return true; // Target found.
            else
                i++; // Move to the next element.
        }
        
        return false; // Target not found.
    }
};

int main() {
    // Instantiate the solution object.
    Solution sol;

    // Example 1:
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    bool result1 = sol.search(nums1, target1);
    cout << "Example 1:" << endl;
    cout << "Input: nums = [2, 5, 6, 0, 0, 1, 2], target = " << target1 << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << endl;

    // Example 2:
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    bool result2 = sol.search(nums2, target2);
    cout << "Example 2:" << endl;
    cout << "Input: nums = [2, 5, 6, 0, 0, 1, 2], target = " << target2 << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;

    return 0;
}
