/**
 * @file removeDuplicates.cpp
 * @brief Naive Version: Remove duplicates from a sorted array in-place.
 * 
 * This file implements a **naive solution** to remove duplicate elements from a
 * sorted integer vector `nums` in-place. In this version, when three or more
 * consecutive duplicates are detected, the extra duplicate is removed by shifting
 * the subsequent elements one position to the left, thereby reducing the effective
 * size of the vector. Note that this approach may have a worst-case time complexity
 * of O(n²).
 * 
 * ## Problem Statement:
 * Given an integer array `nums` sorted in non-decreasing order, remove the duplicates
 * in-place such that each unique element appears only once. Then, return the number of
 * unique elements in `nums`. After the function executes, the first k elements of `nums`
 * should hold the unique elements in their original order, where k is the returned value.
 * The elements beyond the first k are not important.
 * 
 * ## Example:
 * **Input:**  
 * nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
 * 
 * **Output:**  
 * Returns 5, and modifies nums to [0, 1, 2, 3, 4, _, _, _, _, _]  
 * (The underscores denote irrelevant values.)
 * 
 * @author
 * Agustín Coitinho
 * @date
 * 2025
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // n represents the effective size of the vector
        uint16_t n = nums.size();
        uint16_t wr = 2;
        uint16_t rd = 2;
        
        // If the vector has 2 or fewer elements, it already meets the condition.
        if (n <= 2)
            return n;
        
        while (rd < n){
            if (nums[wr-2] == nums[rd]){
                rd++;
            } else {
                nums[wr] = nums[rd];
                wr++;
                rd++;
            }
        }
        
        return wr;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    Solution sol;
    int newLength = sol.removeDuplicates(nums);

    cout << "New size: " << newLength << endl;
    cout << "Modified array: [";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i];
        if (i < newLength - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
