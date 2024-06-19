// 485. Max Consecutive Ones
// Solution 1

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
            }else{
                maxcount = max(count, maxcount);
                count=0;
            }
        }

        // Update maxcount for the case when the array ends with 1s
        maxcount = max(count, maxcount);
        return maxcount;
    }
};