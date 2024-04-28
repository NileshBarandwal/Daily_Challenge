class Solution {
public:
    int divide(int dividend, int divisor) {
          // Check for overflow cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // This case leads to overflow
        }

        // Determine if the result should be negative
        // Dividend: 10
        // Divisor: 2
        // XOR Result: (10 < 0) ^ (2 < 0) → false ^ false → false
        // Interpretation: Since both are positive, the result of the division will also be positive.
        
        bool isNegative = (dividend < 0) ^ (divisor < 0); // XOR to determine the sign of the result
        
        // Work with positive values to avoid overflow issues

        // Use llabs instead of abs
        long long absDividend = llabs((long long)dividend); // Convert to long long to avoid overflow
        long long absDivisor = llabs((long long)divisor); // Ensure divisor is positive for calculations

        long long result = 0;

        // Use a loop to calculate the result using repeated subtraction
        while (absDividend >= absDivisor) {  // Ensure the loop condition is correct
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Double the divisor and multiple while they fit within the dividend
            while ((tempDivisor << 1) <= absDividend) { // Ensuring no overflow
                tempDivisor <<= 1; // Double the divisor
                multiple <<= 1; // Double the multiple
            }

            // Subtract the found multiple from the dividend
            absDividend -= tempDivisor;
            result += multiple;
        }

        // Apply the correct sign to the result
        if (isNegative) {  // Adjust the sign based on the original inputs
            result = -result;  // Convert the result to negative if required
        }

        return result;  // Return the final result after adjusting the sign
    
    }
};