// 1636. Sort Array by Increasing Frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Count frequencies
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Sort the numbers based on frequency and value
        sort(nums.begin(), nums.end(), [&freqMap](int a, int b) {
            // Sort by frequency first (ascending order)
            if (freqMap[a] != freqMap[b]) {
                return freqMap[a] < freqMap[b];
            }
            // If frequencies are the same, sort by value (descending order)
            return a > b;
        });
        
        return nums;
    }
};