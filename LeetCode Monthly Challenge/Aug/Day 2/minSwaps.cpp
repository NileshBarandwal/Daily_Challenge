// 2134. Minimum Swaps to Group All 1's Together II

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count1 = count(nums.begin(), nums.end(), 1);
        if (count1 == 0 || count1 == nums.size()) return 0;
            
        nums.insert(nums.end(), nums.begin(), nums.end()); // Extend the array to handle circular property
        
        int maxOnesInWindow = 0, currentOnes = 0;
        for (int i = 0; i < count1; ++i) {
            if (nums[i] == 1) ++currentOnes;
        }
        maxOnesInWindow = currentOnes;
        
        for (int i = count1; i < nums.size(); ++i) {
            if (nums[i] == 1) ++currentOnes;
            if (nums[i - count1] == 1) --currentOnes;
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
        
        return count1 - maxOnesInWindow;
    }
};
