// 2486. Append Characters to String to Make Subsequence
// Solution 2

class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int j = 0;

        // Traverse through string s
        for (int i = 0; i < slen; ++i) {
            // If the current character of s matches the current character of t
            if (j < tlen && s[i] == t[j]) {
                // Move to the next character in t
                j++;
            }
        }

        // The remaining characters in t that need to be appended to s
        return tlen - j;
        }
};