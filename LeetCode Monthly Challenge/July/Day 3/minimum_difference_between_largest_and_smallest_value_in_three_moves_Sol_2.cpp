// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// Solution 2
// Optimized

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int x = nums.size();
        if (x <= 4) {
            return 0;  // If there are 4 or fewer elements, we can make all the same.
        }

        sort(nums.begin(), nums.end());  // Sort the array.

        // Consider the four scenarios:
        // 1. Change the last three elements.
        // 2. Change the last two elements and the first element.
        // 3. Change the last element and the first two elements.
        // 4. Change the first three elements.
        
        return min({
            nums[x - 4] - nums[0],  // Case 1: smallest and fourth largest.
            nums[x - 3] - nums[1],  // Case 2: second smallest and third largest.
            nums[x - 2] - nums[2],  // Case 3: third smallest and second largest.
            nums[x - 1] - nums[3]   // Case 4: fourth smallest and largest.
        });
    }
};