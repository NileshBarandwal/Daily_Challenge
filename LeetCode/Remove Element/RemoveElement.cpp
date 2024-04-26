class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Pointer to track where to insert non-val elements
        // Iterate over all elements in nums
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) { // If it's not the value to remove
                nums[i] = nums[j]; // Keep it in the result array
                i++; // Move to the next position to fill
            }
        }
        return i; // 'i' will be the new size of the array after removal
    }
};