class Solution(object):
    def intToRoman(self, num):
 """
        :type num: int
        :rtype: str
        """
        # List to map Roman numerals to their integer values
        roman_values = [
            (1000, 'M'),
            (900, 'CM'),
            (500, 'D'),
            (400, 'CD'),
            (100, 'C'),
            (90, 'XC'),
            (50, 'L'),
            (40, 'XL'),
            (10, 'X'),
            (9, 'IX'),
            (5, 'V'),
            (4, 'IV'),
            (1, 'I')
        ]
        
        # Use a list to build the Roman numeral, and then join at the end
        result = []
        
        # Iterate over the Roman values from largest to smallest
        for value, symbol in roman_values:
            # Calculate how many times the current symbol should be used
            count = num // value
            if count > 0:
                # Append the symbol 'count' times
                result.append(symbol * count)
                # Decrement the number by the corresponding total value
                num -= value * count
        
        # Join the list into a single string
        return "".join(result)