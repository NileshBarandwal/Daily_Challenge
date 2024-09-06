// 3217. Delete Nodes From Linked List Present in Array

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set from the vector nums for O(1) lookups
        unordered_set<int> values_to_remove(nums.begin(), nums.end());
        
        // Dummy node to handle edge cases such as removing the head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy; // This will track the previous node

        while (prev->next != nullptr) {
            if (values_to_remove.find(prev->next->val) != values_to_remove.end()) {
                // Remove the node by skipping it
                ListNode* to_delete = prev->next;
                prev->next = prev->next->next;
                delete to_delete; // Free the memory of the removed node
            } else {
                // Move prev to next node if no removal
                prev = prev->next;
            }
        }

        return dummy.next; // Return the new head of the list
    }
};