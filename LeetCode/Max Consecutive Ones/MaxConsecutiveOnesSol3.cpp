// 485. Max Consecutive Ones
// Solution 3
// Optimized 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
            }else{
                count=0;
            }
	maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};