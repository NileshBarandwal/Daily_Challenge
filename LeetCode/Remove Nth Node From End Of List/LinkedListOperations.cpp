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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int length = 1; // Start from 1 to count the head node

        // First pass to find the length of the list
        while (current->next != nullptr) {
            current = current->next;
            length++;
        }

        // Calculate the position to be deleted from the start
        int x = length - n;

        // If x is 0, we need to delete the head node
        if (x == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        current = head;

        // Traverse to the node just before the one to be deleted
        for (int i = 1; i < x; i++) {
            current = current->next;
        }

        // Delete the node
        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;

        return head;
    }
};