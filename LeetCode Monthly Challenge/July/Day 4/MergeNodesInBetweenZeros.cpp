// 2181. Merge Nodes in Between Zeros
// Solve by creating new LinkedList

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
        if (head == nullptr) return nullptr;

        ListNode* current = head->next; // Skip the initial zero
        ListNode* resultHead = new ListNode(); // Dummy node for the result list
        ListNode* resultTail = resultHead; // Tail of the result list
        int sum = 0; // Sum of values between zeros

        while (current != nullptr) {
            if (current->val != 0) {
                // Add the current node's value to the sum
                sum += current->val;
            } else {
                // If the current node's value is zero, it marks the end of a segment
                // Create a new node with the sum and add it to the result list
                resultTail->next = new ListNode(sum);
                resultTail = resultTail->next;
                sum = 0; // Reset the sum for the next segment
            }
            current = current->next; // Move to the next node
        }

        return resultHead->next; // Return the list after the dummy node
    }
};