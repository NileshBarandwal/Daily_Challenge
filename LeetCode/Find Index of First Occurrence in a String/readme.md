# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The goal is to find the index of the first occurrence of a substring (`needle`) within a larger string (`haystack`). Given that `haystack` and `needle` can contain characters and their lengths are bounded, the most straightforward approach is to use a built-in function to search for the substring. Using `std::string::find`, we can locate the position of `needle` within `haystack`.

# Approach
<!-- Describe your approach to solving the problem. -->
To find the index of the first occurrence of `needle` in `haystack`:
1. Check if the `needle` is empty. If it is, the expected result is `0`.
2. Use `heystack.find(needle)` to find the position of `needle` within `haystack`.
3. If the position is within a valid range (between `0` and the length of `haystack`), return the position.
4. If the position is not valid (indicating `needle` isn't found), return `-1`.


For edge cases:
- If `needle` is empty, return `0`.
- If `haystack` is shorter than `needle`, return `-1`.

# Complexity
- Time complexity:
  - The time complexity is approximately $$O(n \times m)$$, where `n` is the length of `haystack` and `m` is the length of `needle`. This reflects the worst-case scenario, but `string::find` is generally optimized.
- Space complexity:
  - The space complexity is $$O(1)$$, as we are using a constant amount of extra space regardless of the input size.

# Example with Detailed Explanation
**Example 1**
- **Input**: `haystack = "hello world"`, `needle = "world"`
- **Expected Output**: `6`
- **Explanation**:
  - The `heystack.find(needle)` method finds "world" in "hello world" at index 6.
  - The function should return this index as the position where `needle` starts in `haystack`.

**Example 2**
- **Input**: `haystack = "hello world"`, `needle = "planet"`
- **Expected Output**: `-1`
- **Explanation**:
  - Since "planet" is not found in "hello world", the function should return `-1`.
  - This indicates that `needle` is not part of `haystack`.

**Edge Case**
- **Input**: `haystack = "example"`, `needle = ""`
- **Expected Output**: `0`
- **Explanation**:
  - When `needle` is empty, the convention is to return `0`, indicating that the empty string is conceptually "found" at any position.


# Code
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { // If needle is empty, the convention is to return 0
            return 0;
        }
        
        // Attempt to find the needle in the haystack
        std::size_t pos = haystack.find(needle);

        // Check if the position is within the bounds of the haystack
        if (pos >= 0 && pos < haystack.size()) {
            return static_cast<int>(pos); // Return the index as an integer
        }

        return -1; // If no valid position found, return -1
    }
};
```