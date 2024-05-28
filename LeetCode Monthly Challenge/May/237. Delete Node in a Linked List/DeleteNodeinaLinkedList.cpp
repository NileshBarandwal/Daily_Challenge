# 237. Delete Node in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
          // Copy the value of the next node into the current node
        node->val = node->next->val;
        // Store the next node temporarily
        ListNode* temp = node->next;
        // Update the current node's next pointer to skip the next node
        node->next = node->next->next;
        // Free the memory of the bypassed node
        delete temp;
    }
};