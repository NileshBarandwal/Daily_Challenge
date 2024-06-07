// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> s1;
        for(int num : nums){
            s1[num]++;
        }

        // Priority queues in C++ by default are max heaps, 
        // meaning elements with the highest priority are at the top. 
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& [key, count] : s1){
            maxHeap.push({count, key});
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};