# Problem Description
Given an array of integers `nums` and an integer `val`, the task is to remove all occurrences of `val` from the `nums` array in-place, returning the new size `k` of the modified array. The order of the elements does not matter, and the content beyond the first `k` elements can be ignored.

## Intuition
The intuition behind this approach is to use two pointers, `i` and `j`, to iterate through the `nums` array. Pointer `i` tracks the position where non-`val` elements should be placed, while pointer `j` traverses the array to find such elements. By overwriting elements at position `i` with non-`val` elements found at position `j`, we effectively remove occurrences of `val` in-place.

## Approach
1. Initialize a pointer `i` to track the position in the array where non-`val` elements should be placed.
2. Loop through the `nums` array with pointer `j`.
3. If `nums[j]` is not equal to `val`, set `nums[i]` to `nums[j]`, then increment `i`.
4. Continue this process until the end of the `nums` array.
5. Return `i` as the new size of the array.

## Complexity
- **Time Complexity**: The time complexity is $$O(n)$$, where `n` is the length of the `nums` array. This is because the loop iterates through each element once.
- **Space Complexity**: The space complexity is $$O(1)$$, since the changes are made in-place without additional memory allocation.

## Detailed Example with Explanation
Consider an array `nums = [0, 1, 2, 2, 3, 0, 4, 2]` and a value `val = 2`:

1. Start with `i = 0`.
2. Loop through the array with pointer `j`:
   - **First iteration** (`j = 0`):
     - `nums[j]` is `0`, not equal to `val`.
     - Set `nums[i] = nums[j]` (`nums[0] = 0`).
     - Increment `i` to `1`.
     - Array: `[0, 1, 2, 2, 3, 0, 4, 2]`.
   - **Second iteration** (`j = 1`):
     - `nums[j]` is `1`, not equal to `val`.
     - Set `nums[i] = nums[j]` (`nums[1] = 1`).
     - Increment `i` to `2`.
     - Array: `[0, 1, 2, 2, 3, 0, 4, 2]`.
   - **Third iteration** (`j = 2`):
     - `nums[j]` is `2`, equal to `val`, so skip it.
     - No changes to `i`.
     - Array: `[0, 1, 2, 2, 3, 0, 4, 2]`.
   - **Fourth iteration** (`j = 3`):
     - `nums[j]` is `2`, equal to `val`, so skip it.
     - No changes to `i`.
     - Array: `[0, 1, 2, 2, 3, 0, 4, 2]`.
   - **Fifth iteration** (`j = 4`):
     - `nums[j]` is `3`, not equal to `val`.
     - Set `nums[i] = nums[j]` (`nums[2] = 3`).
     - Increment `i` to `3`.
     - Array: `[0, 1, 3, 2, 3, 0, 4, 2]`
   - **Sixth iteration** (`j = 5`):
     - `nums[j]` is `0`, not equal to `val`.
     - Set `nums[i] = nums[j]` (`nums[3] = 0`).
     - Increment `i` to `4`.
     - Array: `[0, 1, 3, 0, 3, 0, 4, 2]`
   - **Seventh iteration** (`j = 6`):
     - `nums[j]` is `4`, not equal to `val`.
     - Set `nums[i] = nums[j]` (`nums[4] = 4`).
     - Increment `i` to `5`.
     - Array: `[0, 1, 3, 0, 4, 0, 4, 2]`
   - **Eighth iteration** (`j = 7`):
     - `nums[j]` is `2`, equal to `val`, so skip it.
     - No changes to `i`.
     - Array: `[0, 1, 3, 0, 4, 0, 4, 2]`

3. The final array is `[0, 1, 3, 0, 4, _, _, _]`, where `i = 5`, indicating the new size of the array with elements not equal to `val`.

Returning `5` as the new size represents the first `5` elements in the modified array contain `[0, 1, 3, 0, 4]`, while the content beyond the first `5` elements is not required and can be ignored.

# Code
```
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
```