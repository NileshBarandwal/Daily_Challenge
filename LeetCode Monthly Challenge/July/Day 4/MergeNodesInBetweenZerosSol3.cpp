// 2181. Merge Nodes in Between Zeros
// Update Version of prev one (Without creating new LinkedList, updating existing List).
// Instead of storing sum value from second node onwards, directly update 1st Node with Zero Value and return Head.
// This also Handle nullptr and last node edge case.
// Solution 3

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
                    // Store the sum in the start node
                    start->val = sum;
                    // Move start's next pointer to current's next node (skipping the current zero)
                    start->next = current->next;
                    // Move start to the next node (which is the next segment start)
                    start = current->next;
                    sum = 0; // Reset the sum for the next segment
                }
            }
            current = current->next; // Move to the next node
        }

        return head; // Return the modified list starting from the head
    }
};