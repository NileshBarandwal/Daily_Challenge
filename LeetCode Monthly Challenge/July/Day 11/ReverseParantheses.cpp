// 1190. Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char ch : s) {
            if (ch == '(') {
                st.push(current);
                current = "";
            } else if (ch == ')') {
                reverse(current.begin(), current.end());
                if (!st.empty()) {
                    current = st.top() + current;
                    st.pop();
                }
            } else {
                current += ch;
            }
        }

        return current;
    }
};