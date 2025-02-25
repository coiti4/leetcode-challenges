/**
 * @file searchInsertPosition.cpp
 * @brief Search Insert Position Finder
 * 
 * This file implements a solution to find the index where a target value should be inserted into a sorted array.
 * The algorithm uses binary search to achieve this efficiently.
 * 
 * ## Problem Statement:
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * 
 * ## Example:
 * **Input:** nums = [1,3,5,6], target = 5
 * **Output:** 2
 * 
 * **Input:** nums = [1,3,5,6], target = 2
 * **Output:** 1
 * 
 * **Input:** nums = [1,3,5,6], target = 7
 * **Output:** 4
 * 
 * **Constraints:**
 * - 1 <= nums.length <= 10^4
 * - -10^4 <= nums[i] <= 10^4
 * - nums contains distinct values sorted in ascending order.
 * - -10^4 <= target <= 10^4
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>
#include <algorithm> // Para std::lower_bound

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};

/**
 * @brief Main function to test the searchInsert function
 */
int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    int target2 = 2;
    int target3 = 7;

    cout << "Test 1: " << solution.searchInsert(nums1, target1) << endl; // Expected: 2
    cout << "Test 2: " << solution.searchInsert(nums1, target2) << endl; // Expected: 1
    cout << "Test 3: " << solution.searchInsert(nums1, target3) << endl; // Expected: 4

    return 0;
}
