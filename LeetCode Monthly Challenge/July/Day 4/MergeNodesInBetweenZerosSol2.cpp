// 2181. Merge Nodes in Between Zeros
// Without creating new LinkedList, updating existing List.
// Storing sum value from second node onwards and return head->next;
// Solution 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head->next; // Start from the node after the initial zero
        ListNode* start = head; // Start from the initial zero node
        int sum = 0; // Sum of values between zeros

        while (current != nullptr) {
            if (current->val != 0) {
                // Add the current node's value to the sum
                sum += current->val;
            } else {
                // If the current node's value is zero, it marks the end of a segment
                if (sum != 0) {
                    // Store the sum in the next node of start
                    start->next->val = sum;
                    // Move start to the next node (which is the sum node now)
                    start = start->next;
                    sum = 0; // Reset the sum for the next segment
                }
            }
            current = current->next; // Move to the next node
        }

        // Make sure to cut off any trailing zeros
        start->next = nullptr;

        return head->next; // Return the list starting from the node after the initial zero
    }
};