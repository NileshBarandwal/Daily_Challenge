// 2486. Append Characters to String to Make Subsequence
// Solution 1

class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int j = 0;

        for (char i : s) {
            if (j < tlen && i == t[j]) {
                j++;
            }
        }

        return tlen-j;
        }
};