/**
 * @file merge.cpp
 * @brief Merging two sorted arrays into a single sorted array in-place.
 * 
 * This program implements a function that merges two sorted integer arrays `nums1` and `nums2`
 * into a single sorted array. The merging is done in-place within `nums1`, assuming that it has 
 * enough space to accommodate elements from `nums2`.
 * 
 * ## Problem Statement:
 * Given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, merge them 
 * into `nums1` as one sorted array. The number of elements initialized in `nums1` is `m`, and
 * the number of elements in `nums2` is `n`. The array `nums1` has a size of `m + n`, with the 
 * last `n` positions filled with zeroes as placeholders.
 * 
 * ## Example:
 * **Input:**  
 * nums1 = [1, 2, 3, 0, 0, 0], m = 3  
 * nums2 = [2, 5, 6], n = 3  
 * 
 * **Output:**  
 * nums1 = [1, 2, 2, 3, 5, 6]
 * 
 * ## Edge Cases:
 * - `nums2` is empty (`n == 0`).
 * - `nums1` is empty (`m == 0`, but `nums1` still has size `n`).
 * - All elements of `nums2` are greater than those in `nums1`.
 * - All elements of `nums2` are smaller than those in `nums1`.
 * 
 * @author Agustín Coitinho
 * @date 2025
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Merges two sorted arrays into one sorted array in-place.
     * 
     * @param nums1 The first sorted array with a size of `m + n`. The first `m` elements 
     *              are valid, and the last `n` are placeholders (zeroes).
     * @param m The number of valid elements in `nums1`.
     * @param nums2 The second sorted array with `n` elements.
     * @param n The number of elements in `nums2`.
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy the valid elements of nums1 into a temporary array (nums3)
        vector<int> nums3(nums1.begin(), nums1.begin() + m);

        int i = 0; // Index for nums3 (original nums1)
        int j = 0; // Index for nums2
        int k = 0; // Index for nums1 (final merged result)

        // Merge elements from nums3 and nums2 into nums1
        while (i < m && j < n) {
            if (nums3[i] < nums2[j]) {
                nums1[k++] = nums3[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        // Copy any remaining elements from nums3
        while (i < m) {
            nums1[k++] = nums3[i++];
        }

        // Copy any remaining elements from nums2
        while (j < n) {
            nums1[k++] = nums2[j++];
        }
    }
}; 

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has extra space for nums2
    vector<int> nums2 = {2, 5, 6};          // nums2 is another sorted array

    sol.merge(nums1, 3, nums2, 3); // Merge nums2 into nums1

    // Print the merged result
    for (size_t i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
