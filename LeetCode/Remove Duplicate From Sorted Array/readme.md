# Intuition
To remove duplicates from a sorted array, the general intuition is that we only need to keep track of unique elements and skip duplicates. Because the array is sorted, duplicates are adjacent, allowing us to compare current elements with the previous ones to identify uniqueness. The goal is to modify the array in-place, maintaining the order of unique elements.

# Approach
To solve the problem, we can use a "slow" pointer `i` to track where to insert the next unique element, and a "fast" pointer `j` to traverse the array. The approach involves the following steps:

1. **Initialization**:
   - Start with `i = 1`, as the first element is always unique.
   - The "fast" pointer `j` iterates through the array from the second element.

2. **Loop through `nums`**:
   - Compare `nums[j]` with `nums[j - 1]`.
   - If they are different, then `nums[j]` is a unique element, so we copy it to `nums[i]`, then increment `i`.
   - If they are the same, it's a duplicate, so we skip it and continue the loop.

3. **Return the New Size**:
   - After completing the loop, return `i` as the count of unique elements.

# Complexity
- **Time Complexity**:
  The time complexity is $$O(n)$$, where `n` is the length of the `nums` array, because the loop iterates through each element once.

- **Space Complexity**:
  The space complexity is $$O(1)$$, as we are modifying the array in-place and don't require additional storage beyond the pointers used.

# Example with Detail Working
Consider the array `nums = [1, 1, 2, 2, 3, 4, 4]`:

1. **Initialization**:
   - `i = 1`
   - The loop starts from `j = 1`

2. **Iteration through the array**:
   - **First iteration (`j = 1`)**:
     - `nums[j]` is `1`
     - `nums[j - 1]` is also `1`
     - Since they're equal, it's a duplicate, so skip it.
   - **Second iteration (`j = 2`)**:
     - `nums[j]` is `2`
     - `nums[j - 1]` is `1`
     - Since they're different, copy `nums[j]` to `nums[i]`: `nums[1] = 2`
     - Increment `i` to `2`
   - **Third iteration (`j = 3`)**:
     - `nums[j]` is `2`
     - `nums[j - 1]` is also `2`
     - They are duplicates, so skip it.
   - **Fourth iteration (`j = 4`)**:
     - `nums[j]` is `3`
     - `nums[j - 1]` is `2`
     - Copy `nums[j]` to `nums[i]`: `nums[2] = 3`
     - Increment `i` to `3`
   - **Fifth iteration (`j = 5`)**:
     - `nums[j]` is `4`
     - `nums[j - 1]` is `3`
     - Copy `nums[j]` to `nums[i]`: `nums[3] = 4`
     - Increment `i` to `4`
   - **Sixth iteration (`j = 6`)**:
     - `nums[j]` is `4`
     - `nums[j - 1]` is also `4`
     - They are duplicates, so skip it.

3. **Return the Final Count**:
   - The final value of `i` is `4`, indicating the number of unique elements.
   - The modified array is `[1, 2, 3, 4, _, _, _]`.
   - The return value `4` represents the unique elements count.

This example provides detailed steps to understand the working of the solution, explaining how the duplicates are removed while keeping the order intact.

# Code
```
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
```