/**
 * @file removeElement.cpp
 * @brief Removes all occurrences of a given value from an integer array in-place.
 *
 * This file implements a solution for removing all instances of a specified value
 * from an integer array in-place. The order of the remaining elements may be changed.
 * The function returns the number of elements not equal to the specified value,
 * and modifies the array such that the first k elements contain the elements not equal
 * to the specified value.
 *
 * Example:
 *   Input: nums = [3,2,2,3], val = 3
 *   Output: 2, nums = [2,2,_,_]
 *
 *   Input: nums = [0,1,2,2,3,0,4,2], val = 2
 *   Output: 5, nums = [0,1,4,0,3,_,_,_]
 *
 * Constraints:
 *   - 0 <= nums.length <= 100
 *   - 0 <= nums[i] <= 50
 *   - 0 <= val <= 100
 *
 * @author Agustin Coitinho
 * @date 2025
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

class Solution {
public:
    /**
     * @brief Removes all occurrences of val in nums in-place.
     *
     * This function modifies the input vector nums by removing all elements
     * equal to val. It uses the std::remove algorithm to shift the elements
     * not equal to val to the front of the vector and then erases the remaining
     * elements. The function returns the new size of the vector, which is the
     * number of elements not equal to val.
     *
     * @param nums The input vector of integers.
     * @param val The value to be removed from the vector.
     * @return The number of elements in nums that are not equal to val.
     */
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main() {
    Solution solution;

    // Test case 1: nums = [3,2,2,3], val = 3
    // Expected k = 2, first k elements: [2,2]
    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int expectedK1 = 2;
    std::vector<int> expectedNums1 = {2, 2}; // already sorted
    int k1 = solution.removeElement(nums1, val1);
    assert(k1 == expectedK1);
    std::vector<int> firstK1(nums1.begin(), nums1.begin() + k1);
    std::sort(firstK1.begin(), firstK1.end());
    assert(firstK1 == expectedNums1);

    // Test case 2: nums = [0,1,2,2,3,0,4,2], val = 2
    // Expected k = 5, first k elements: [0,0,1,3,4]
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int expectedK2 = 5;
    std::vector<int> expectedNums2 = {0, 0, 1, 3, 4}; // sorted
    int k2 = solution.removeElement(nums2, val2);
    assert(k2 == expectedK2);
    std::vector<int> firstK2(nums2.begin(), nums2.begin() + k2);
    std::sort(firstK2.begin(), firstK2.end());
    assert(firstK2 == expectedNums2);

    // Test case 3: empty array
    // Expected k = 0
    std::vector<int> nums3 = {};
    int val3 = 1;
    int expectedK3 = 0;
    std::vector<int> expectedNums3 = {};
    int k3 = solution.removeElement(nums3, val3);
    assert(k3 == expectedK3);
    std::vector<int> firstK3(nums3.begin(), nums3.begin() + k3);
    std::sort(firstK3.begin(), firstK3.end());
    assert(firstK3 == expectedNums3);

    // Test case 4: all elements are val
    // Expected k = 0
    std::vector<int> nums4 = {1, 1, 1};
    int val4 = 1;
    int expectedK4 = 0;
    std::vector<int> expectedNums4 = {};
    int k4 = solution.removeElement(nums4, val4);
    assert(k4 == expectedK4);
    std::vector<int> firstK4(nums4.begin(), nums4.begin() + k4);
    std::sort(firstK4.begin(), firstK4.end());
    assert(firstK4 == expectedNums4);

    // Test case 5: no elements are val
    // Expected k = 3, first k elements: [1,2,3]
    std::vector<int> nums5 = {1, 2, 3};
    int val5 = 4;
    int expectedK5 = 3;
    std::vector<int> expectedNums5 = {1, 2, 3}; // sorted
    int k5 = solution.removeElement(nums5, val5);
    assert(k5 == expectedK5);
    std::vector<int> firstK5(nums5.begin(), nums5.begin() + k5);
    std::sort(firstK5.begin(), firstK5.end());
    assert(firstK5 == expectedNums5);

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
