// 725. Split Linked List in Parts

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // First, compute the length of the linked list
        int total_length = 0;
        ListNode* current = head;
        while (current) {
            total_length++;
            current = current->next;
        }
        
        // Calculate the size of each part and the number of parts with an extra node
        int part_size = total_length / k;
        int extra_nodes = total_length % k;
        
        vector<ListNode*> result(k, nullptr);
        current = head;
        
        for (int i = 0; i < k; ++i) {
            ListNode* part_head = current;
            ListNode* part_tail = nullptr;
            int current_part_size = part_size + (extra_nodes > 0 ? 1 : 0);
            if (extra_nodes > 0) {
                extra_nodes--;
            }
            
            // Traverse the current part
            for (int j = 1; j < current_part_size; ++j) {
                if (current) {
                    current = current->next;
                }
            }
            
            if (current) {
                part_tail = current;
                current = current->next;
                part_tail->next = nullptr;
            }
            
            result[i] = part_head;
        }
        
        return result;
    }
};
