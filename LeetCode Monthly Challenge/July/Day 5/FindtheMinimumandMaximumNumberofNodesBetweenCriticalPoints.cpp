// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Vector to store the positions of critical points
        vector<int> criticalPoints;
        
        // Initialize pointers
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head ? head->next : nullptr;
        
        // Position counter
        int pos = 1;
        
        while (next) {
            if (prev && curr) {
                // Check for local maxima or minima
                if ((curr->val > prev->val && curr->val > next->val) ||
                    (curr->val < prev->val && curr->val < next->val)) {
                    criticalPoints.push_back(pos);
                }
            }
            // Move to the next node
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }
        
        // If there are fewer than two critical points, return [-1, -1]
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        // Calculate minimum and maximum distances
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        for (size_t i = 1; i < criticalPoints.size(); i++) {
            int distance = criticalPoints[i] - criticalPoints[i - 1];
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
        
        return {minDistance, maxDistance};
    }
};
