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
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *prev, *n;
        current = head;
        prev = nullptr;
        while(current!=nullptr){
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        head = prev;

        return head;
    }
};