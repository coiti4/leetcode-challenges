/**
 * @file mergeSortedLists.cpp
 * @brief Merges two sorted linked lists into one sorted list.
 *
 * This file contains a solution to merge two sorted linked lists by
 * splicing together their nodes.
 *
 * ## Problem Statement:
 * Given the heads of two sorted linked lists, merge them into one sorted list.
 * The list should be made by splicing together the nodes of the first two lists.
 *
 * ## Example:
 * **Input:** list1 = [1,2,4], list2 = [1,3,4]
 * **Output:** [1,1,2,3,4,4]
 *
 * **Input:** list1 = [], list2 = []
 * **Output:** []
 *
 * **Input:** list1 = [], list2 = [0]
 * **Output:** [0]
 * 
 * ## Constraints:
 * - The number of nodes in both lists is in the range [0, 50].
 * - 100 <= Node.val <= 100
 * - Both list1 and list2 are sorted in non-decreasing order.
 * 
 * @author Agustin Coitinho
 * @date 2025
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        
        ListNode* dummy = new ListNode(); // dummy -> nullptr. Useful to keep track on the initial node.
        ListNode* current = dummy; // current -> dummy

        while (list1 && list2){ 
            if (list1->val <= list2->val){
                current->next = list1; // links list1
                list1 = list1->next;   // advances list1
            } else {
                current->next = list2; // links list2
                list2 = list2->next;   // advances list2
            }
            current = current->next; // advances current
        }

        if (list1){
            current->next = list1;
        } else if (list2){
            current->next = list2;
        }

        return dummy->next;
    }
};

/**
 * @brief Helper function to print a linked list.
 */
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/**
 * @brief Main function to test mergeTwoLists.
 */
int main() {
    // Example lists: list1 = [1,2,4], list2 = [1,3,4]
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(mergedList);
    
    return 0;
}
