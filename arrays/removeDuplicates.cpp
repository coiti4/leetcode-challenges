/**
 * @file removeDuplicates.cpp
 * @brief Removes duplicates from a sorted array in-place.
 * 
 * This program implements a function that removes duplicate elements from a sorted
 * integer vector `nums` in-place, ensuring that each unique element appears only once.
 * The relative order of the elements is maintained. The function returns the number of
 * unique elements in the vector.
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
 * @date 2025
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use uint16_t for indices i and j
        uint16_t i = 0;
        uint16_t j = 1;

        // Handle edge case: if the vector has only one element, it's already unique.
        if (nums.size() == 1) {
            return 1;
        }

        // Iterate through the vector using i as the index for unique elements.
        for (i = 0; i <= nums.size(); i++){
            if (j < nums.size()){
                // Advance j while the current element equals nums[i]
                while (j < nums.size() && nums[i] == nums[j]){
                    j++;
                }
                // If a new unique element is found, assign it to position i+1
                if (i + 1 != nums.size() && j < nums.size()){
                    nums[i + 1] = nums[j];
                }
            } else {
                // Break out of the loop if j reaches the end of the vector
                break;
            }
        }
        // Return the number of unique elements (i is the last index where a unique element was placed)
        return i;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

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
