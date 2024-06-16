// 330. Patching Array
// Solution 2

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
    long long covered = 0; // Using long long to avoid overflow issues
    
    int i = 0;
    while (covered < n) {
        if (i < nums.size() && nums[i] <= covered + 1) {
            covered += nums[i++];
        } else {
            covered += covered + 1;
            patches++;
        }
    }
    
    return patches;

    }
};