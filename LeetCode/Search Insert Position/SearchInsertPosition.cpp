class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // If target is found, return its index
            } else if (nums[mid] < target) {
                left = mid + 1;  // Continue searching on the right side
            } else {
                right = mid - 1;  // Continue searching on the left side
            }
        }
        
        // If target is not found, return the insertion point
        return left;
    }
};