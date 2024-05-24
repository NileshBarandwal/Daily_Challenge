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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node before left position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Reverse the sublist from left to right
        ListNode* curr = prev->next;
        ListNode* n = curr->next;
        for (int i = 0; i < right - left; ++i) {
            curr->next = n->next;
            n->next = prev->next;
            prev->next = n;
            n = curr->next;
        }

        return dummy->next;
    }
};
