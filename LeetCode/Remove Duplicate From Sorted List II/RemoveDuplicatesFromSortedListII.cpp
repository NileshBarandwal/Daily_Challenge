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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* duplicate = new ListNode(0);
        duplicate->next=head;
        ListNode* prev = duplicate;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }else{
                prev=prev->next;
            }
            head=head->next;
        }
        ListNode* new_head = duplicate->next;
        delete duplicate;
        return new_head;
    }
};