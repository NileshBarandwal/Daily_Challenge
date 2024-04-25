class Solution {
public:
    bool isValid(string s) {
 // Initialize a stack to track open brackets
        stack<char> stack;
        // Mapping of closing brackets to their corresponding opening brackets
        unordered_map<char, char> matching = {
            {')', '('}, // Matches closing to opening brackets
            {']', '['},
            {'}', '{'}
        };

        // Loop through each character in the input string
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                // If it's an opening bracket, push it onto the stack
                stack.push(c);
            } else {
                // If it's a closing bracket
                if (stack.empty() || stack.top() != matching[c]) {
                    // If the stack is empty or the top doesn't match the closing bracket, it's invalid
                    return false;
                }
                // Pop the matching opening bracket
                stack.pop();
            }
        }

        // The stack should be empty for a valid bracket sequence
        return stack.empty();
    }
};