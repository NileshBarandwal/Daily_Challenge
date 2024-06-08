// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1; // Initialize with remainder 0 at index -1
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            int remainder = k != 0 ? prefixSum % k : prefixSum;
            
            if (remainderMap.find(remainder) != remainderMap.end()) {
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};