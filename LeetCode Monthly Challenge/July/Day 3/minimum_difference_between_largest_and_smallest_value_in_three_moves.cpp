// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int x = nums.size();
        if (x <= 4) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int mindiff = INT_MAX;

        mindiff = min(mindiff, nums[x - 4] - nums[0]);
        mindiff = min(mindiff, nums[x - 3] - nums[1]);
        mindiff = min(mindiff, nums[x - 2] - nums[2]);
        mindiff = min(mindiff, nums[x - 1] - nums[3]);

        return mindiff;
    }
};