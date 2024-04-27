class Solution(object):
    def intToRoman(self, num):        
	"""
        :type num: int
        :rtype: str
        """
         # Dictionary to map Roman numerals to their integer values
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
        
        # Initialize result
        result = ''

        for value, symbol in roman_values:
            while num>=value:
                result+=symbol
                num-=value

        return result