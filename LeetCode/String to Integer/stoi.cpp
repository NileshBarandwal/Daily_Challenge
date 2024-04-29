class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long result = 0; // Using long to detect overflow

        // Step 1: Ignore leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert characters to integer
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow/underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return static_cast<int>(result * sign);
    }
};