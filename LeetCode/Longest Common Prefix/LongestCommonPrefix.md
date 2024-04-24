# Longest Common Prefix

The problem is to find the longest common prefix among a list of strings. The common prefix is a sequence of characters at the beginning of each string. This solution employs an iterative approach to determine the longest common prefix by progressively shortening it until it aligns with the start of each string in the list.

## Approach
1. **Initialization**: Start with the first string in the list as the initial `prefix`.
2. **Check Against All Strings**: Loop through the remaining strings to ensure each one starts with the current `prefix`.
   - If a string doesn't start with `prefix`, shorten the `prefix` by removing characters from the end.
3. **Return the Result**: If the `prefix` becomes empty, return an empty string (indicating there's no common prefix). Otherwise, return the final `prefix` after checking all strings.

## Complexity
- **Time complexity**:
  - The worst-case time complexity is O(n * m), where `n` is the number of strings and `m` is the length of the longest string. This accounts for the loop's iterative trimming of the `prefix`, possibly shortening it one character at a time.
  
- **Space complexity**:
  - The space complexity is O(1), since only a single variable (`prefix`) is used to store the result, with no additional data structures required.

## Example
Here's an example that demonstrates how the code works to find the longest common prefix among the strings `"flight"`, `"flow"`, and `"flower"`:

## Explanation of the Example with "flower", "flow", "flight"

### Initialization
- The initial `prefix` is set to `"flower"`, the first string in the array.

### First Loop Iteration
- The loop checks the second string, `"flow"`.
- The `while` loop condition (`str.find(prefix) != 0`) is true because `"flow"` doesn't start with `"flower"`.
- The loop then shortens the `prefix` by one character, making it `"flowe"`. It still doesn't match the beginning of `"flow"`.
- The loop continues to shorten `"flowe"` to `"flow"`, at which point `"flow"` starts with `"flow"`, ending the `while` loop condition.

### Second Loop Iteration
- Now the loop checks the third string, `"flight"`, with the current `prefix` (`"flow"`).
- Since `"flight"` doesn't start with `"flow"`, the `while` loop condition is true.
- The loop shortens the `prefix` to `"flo"`, then to `"fl"`.
- At `"fl"`, `"flight"` starts with the `prefix`, ending the `while` loop condition.

### Final Result
- At this point, the `prefix` is `"fl"`, which is the longest common prefix among `"flower"`, `"flow"`, and `"flight"`.
- Since all the strings start with `"fl"`, the function returns `"fl"`.


```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) { // If the input list is empty, return an empty string.
            return "";
        }

        // Initialize the prefix with the first string.
        std::string prefix = strs[0]; 

        // Loop through each string in the list (from the second string onwards).
        for (const auto& str : strs) {
            // While the current string doesn't start with the prefix.
            while (str.find(prefix) != 0) {
                // Shorten the prefix by one character from the end.
                prefix = prefix.substr(0, prefix.length() - 1);

                // If the prefix becomes empty, there's no common prefix.
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        // Return the longest common prefix found.
        return prefix;
    }
};

int main() {
    // Example input with "flight", "flow", "flower".
    std::vector<std::string> strs = {"flight", "flow", "flower"};

    Solution sol;
    std::string result = sol.longestCommonPrefix(strs);

    std::cout << "Longest Common Prefix: " << result << std::endl; // Output: "fl"

    return 0;
}
