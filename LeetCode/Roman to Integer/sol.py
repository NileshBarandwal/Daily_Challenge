class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Dictionary to map Roman numerals to their integer values
        roman_values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        # Initialize result
        result = 0
        
        # Iterate through the string
        for i in range(len(s)):
            # If current numeral is smaller than the next one, it's a subtraction case
            if i < len(s) - 1 and roman_values[s[i]] < roman_values[s[i + 1]]:
                result -= roman_values[s[i]]
            else:
                result += roman_values[s[i]]
        
        return result