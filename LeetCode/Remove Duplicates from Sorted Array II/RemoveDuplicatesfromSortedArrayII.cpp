class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            // If the size is 2 or less, no need to do anything because all elements can stay.
            return n;
        }

        // This `writeIndex` will keep track of the position to write unique values, allowing at most twice of each.
        int writeIndex = 2;

        for (int i = 2; i < n; i++) {
            // Check if the current element is different from the `writeIndex - 2` element.
            // If true, it means it's not a third (or more) repetition.
            if (nums[i] != nums[writeIndex - 2]) {
                nums[writeIndex] = nums[i]; // Write to `writeIndex` if it's valid
                writeIndex++; // Move the write index
            }
        }

        return writeIndex; // This indicates the new size with at most two duplicates
    }
};