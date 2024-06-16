// 330. Patching Array
// Solution 1

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1; // The smallest number that cannot be formed
        int patches = 0; // Count of patches added
        int i = 0;
        int size = nums.size();
        
        while (miss <= n) {
            if (i < size && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patches++;
            }
        }
        
        return patches;

    }
};