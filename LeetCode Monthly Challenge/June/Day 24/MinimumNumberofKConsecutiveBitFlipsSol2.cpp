// 995. Minimum Number of K Consecutive Bit Flips
// SOlution 2

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
int n = nums.size();
        int flipCount = 0;
        std::queue<int> flipQueue;
        
        for (int i = 0; i < n; ++i) {
            // If the element at nums[i] needs to be flipped
            if (!flipQueue.empty() && i >= flipQueue.front() + k) {
                flipQueue.pop();
            }
            
            if (flipQueue.size() % 2 == nums[i]) {
                if (i + k > n) {
                    return -1; // Cannot flip if there are less than k elements remaining
                }
                flipCount++;
                flipQueue.push(i);
            }
        }
        
        return flipCount;
    }
};