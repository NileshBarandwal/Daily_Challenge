# Intuition
The idea is to convert an integer into its Roman numeral representation by breaking it down into known Roman symbols. Each Roman symbol has a specific value, so by iterating from the highest value to the lowest, we can build the Roman numeral string.

# Approach
The approach involves iterating over a list of Roman numeral values and their corresponding symbols, ordered from largest to smallest. At each step, we determine how many times the current Roman value fits into the given integer and append the corresponding symbol(s) to our result list. We then subtract the total value represented by the appended symbols from the integer. Finally, we join the result list into a single Roman numeral string.

### Steps:
1. **Initialization**: Define a list of Roman numeral values and their symbols, from largest to smallest.
2. **Symbol Addition**: Iterate through the list, checking how many times a Roman value can fit into the given integer. Add the corresponding Roman symbol(s) to the result list and subtract the total represented value from the integer.
3. **Output**: Join the result list into a single string to get the Roman numeral representation.

### Example
Given the integer `58`, the conversion process is as follows:

1. **Roman Numeral Breakdown**:
   - `M` (1000) is too large, so move to the next.
   - `CM` (900) is too large, move to `D` (500), also too large.
   - `CD` (400), `C` (100), `XC` (90), all too large.
   - `L` (50) fits once into `58`.
   - `VIII` (5, 3 times) builds from the remaining `8`.

2. **Result**:
   - After appending symbols, the result becomes `'LVIII'`.

# Complexity
- **Time complexity**:
  The time complexity for this algorithm is \( O(1) \) because it always loops through a fixed number of Roman numeral values, regardless of the input size.

- **Space complexity**:
  The space complexity is also \( O(1) \) since the maximum length of a Roman numeral is limited by the structure of the Roman numeral system. The result list grows in proportion to the required Roman symbols, but there's a fixed upper limit.


# Code
```python []
# Code Snippet 1 : Optimized version

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
```

```python []
# Code Snippet 2:

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
```

