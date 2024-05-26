# 234. Palindrome Linked List

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true; // Empty or single node list is a palindrome
        
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Compare the first half with the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val)
                return false; // Not a palindrome
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true; // Palindrome
    }
};
