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