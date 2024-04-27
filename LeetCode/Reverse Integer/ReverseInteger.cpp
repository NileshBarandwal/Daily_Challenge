class Solution {
public:
    int reverse(int x) {
        // Check for the special case where x is INT_MIN
        if (x == -2147483648) {
            return 0; // Negating INT_MIN would cause overflow
        }

        int reverse = 0; // Store the reversed integer
        bool isNegative = x < 0; // Check if the number is negative
        
        // Convert negative numbers to positive for easier manipulation
        if (isNegative) {
            x = -x; // Now work with a positive number
        }

        // Loop to reverse the digits
        while (x != 0) {
            int lastDigit = x % 10; // Extract the last digit

            // Check for overflow before the multiplication and addition
            // -2^31 <= x <=2^31 - 1
            // 2^31 = 2147483648
            // 2147483648%10 = 214748364
            // lastdigit = 8
            // This will cause overflow, return 0 in this case
            if (reverse > 214748364 || 
                (reverse == 214748364 && lastDigit > 7)) {
                return 0; // Would cause overflow, return 0
            }

            reverse = reverse * 10 + lastDigit; // Rebuild the reversed integer
            x /= 10; // Remove the last digit
        }

        // Reapply the negative sign if the original number was negative
        if (isNegative) {
            reverse = -reverse; // Make the reversed number negative
        }

        return reverse; // Return the final reversed integer
    }
};