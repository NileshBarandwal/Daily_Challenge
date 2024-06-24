// 995. Minimum Number of K Consecutive Bit Flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;
        vector<int> flipped(n, 0); // To keep track of flips
        
        int currentFlips = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                currentFlips ^= flipped[i - k]; // Undo the effect of old flip if it's outside current window
            }
            
            // If current element still needs flipping (after undoing previous flips)
            if ((nums[i] + currentFlips) % 2 == 0) {
                if (i + k > n) { // Cannot flip if there are less than k elements remaining
                    return -1;
                }
                // Perform a flip at position i
                flipCount++;
                currentFlips ^= 1; // flip current segment
                flipped[i] = 1;
            }
        }
        
        return flipCount;
    }
};
