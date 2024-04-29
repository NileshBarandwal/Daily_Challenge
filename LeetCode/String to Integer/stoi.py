class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Constants for 32-bit signed integer limits
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        
        # Initial index
        i = 0
        # Sign, default to positive
        sign = 1
        # Result to accumulate the digits
        result = 0

        # Skip leading whitespace
        while i < len(s) and s[i]==' ':
            i += 1  # Move past whitespace

        # Determine the sign if there's one
        if i < len(s) and (s[i] == '+' or s[i] == '-'):
            sign = -1 if s[i] == '-' else 1  # Set the correct sign
            i += 1  # Move past the sign character

        # Parse digits
        while i < len(s) and s[i].isdigit():
            result = result * 10 + int(s[i])  # Convert and accumulate digits
            
            # Check for overflow and underflow
            if sign * result > INT_MAX:
                return INT_MAX  # Clamp to INT_MAX
            elif sign * result < INT_MIN:
                return INT_MIN  # Clamp to INT_MIN
            
            i += 1  # Move to the next digit

        # Return the final result with the correct sign
        return sign * result  # Return the final integer with the appropriate sign
