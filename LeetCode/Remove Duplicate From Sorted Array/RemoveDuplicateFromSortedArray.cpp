class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If nums is empty, return 0
        if (nums.size() == 0) {
            return 0;
        }

        int i = 1; // Start at the second position
        // Iterate from the second element to the end
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) { // If it's a new unique element
                nums[i] = nums[j]; // Store it at position 'i'
                i++; // Increment 'i' to track unique element count
            }
        }
        return i; // 'i' is the new size of the array with unique element
    }
};