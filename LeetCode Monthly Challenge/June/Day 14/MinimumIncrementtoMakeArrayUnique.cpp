// 945. Minimum Increment to Make Array Unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int minIncrements = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            // 2 2  not unique or 3 2 not correct order
            if (nums[i] <= nums[i - 1]) {
                // Inorder to make i value greater than i-1 get +1 value of i-1
                // then sub with i to get min difference
                // e.g. 3 2 In order to make 2 > 3 we find mingreater value of 3 i.e 3+1=4
                // then sub 4-2 = 2 min diff to add to 2 to be > than 3
                // then update 4 with 2
                // So inshort
                // we are just doing
                // num[i-1]+1
                // for each element from index 1 till end
                int required = nums[i - 1] + 1;
                minIncrements += required - nums[i];
                nums[i] = required;
            }
        }
        
        return minIncrements;
    }
};