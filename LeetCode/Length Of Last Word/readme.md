# Problem Statement
Given a string `s` consisting of words and spaces, find the length of the last word in the string.

# Intuition
- The last word in a string is defined as the maximal substring consisting of non-space characters at the end of the string.
- To find the length of the last word, we can ignore trailing spaces and then count the number of characters in the last word before a space.

# Approach
1. **Skip Trailing Spaces**: 
   - Start from the end of the string and move backward, ignoring spaces, to reach the end of the last word.
2. **Count Characters in the Last Word**: 
   - Continue moving backward until a space or the start of the string is reached, counting the number of characters (which gives the length of the last word).

# Complexity
- **Time Complexity**: $$O(n)$$, where `n` is the length of the input string `s`. This is because we traverse the string once from the end to the beginning.
- **Space Complexity**: $$O(1)$$, as only a constant amount of extra space is used to store the count and loop variable.

# Example and Step-by-Step Solution
Consider the input string: `"   fly me   to   the moon  "`.
1. **Initialize Variables**: 
   - Set `i = len(s) - 1` (index of the last character in the string).
   - Set `result = 0` to keep track of the length of the last word.
2. **Skip Trailing Spaces**:
   - Move `i` backward while `s[i]` is a space (`s[i] == ' '`). 
   - After skipping trailing spaces, `i` will point to the last character in the last word (`i = 28` for this example).
3. **Count the Characters in the Last Word**:
   - Move `i` backward while `s[i]` is not a space (`s[i] != ' '`). 
   - Increment `result` for each non-space character encountered.
   - For this example, the last word is `"moon"`, with a length of `4`.
   - `result` should be updated to `4`.
4. **Return the Result**:
   - Return `result`, which is the length of the last word.

This step-by-step solution correctly identifies the last word and computes its length in an efficient manner.


# Code
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int i = length - 1;
        int result = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            result++;
            i--;
        }

        return result;
    }
};
```