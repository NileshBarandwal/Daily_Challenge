# Roman To Integer

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.
```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

`I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
`X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
`C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

## Example 1:
```
Input: s = "III"
Output: 3
Explanation: III = 3.
```

## Example 2:
```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

## Example 3:
```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## Constraints:

`1 <= s.length <= 15`

`s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.

It is guaranteed that s is a valid roman numeral in the range `[1, 3999]`.

# Intuition
The problem involves converting Roman numerals to integers. We need to handle special cases where subtraction is used. Our intuition is to iterate through the Roman numeral string, adding or subtracting values based on the special cases.

# Approach
We'll create a dictionary to map Roman numerals to their integer values. Then, we'll initialize the result variable to 0 and iterate through the string. If the current numeral is smaller than the next one, indicating a subtraction case, we'll subtract its value; otherwise, we'll add its value to the result.

# Complexity
- Time complexity: O(n), where n is the length of the input Roman numeral string.
- Space complexity: O(1) since the space used does not grow with the size of the input.

# Example and Explanation 1

Let's consider the Roman numeral `IV` and see how the code works with it.

Given Roman numeral: `IV`

```
Step 1: Initialize result = 0
Step 2: Iterate through the string "IV"
    - At index 0: s[0] = 'I'
        - Since 'I' < 'V' (the next character), it's a subtraction case. So, we subtract 1 from the result.
        - Result = 0 - 1 = -1
    - At index 1: s[1] = 'V'
        - There's no next character, so we simply add the value of 'V' (5) to the result.
        - Result = -1 + 5 = 4

Final result: 4

So, the integer value of the Roman numeral "IV" is 4.
```

# Example and Explanation 2

Let's consider the Roman numeral `LVIII` and see how the code works with it.

Given Roman numeral: `LVIII`
```
Step 1: Initialize result = 0
Step 2: Iterate through the string "LVIII"
    - At index 0: s[0] = 'L'
        - Since 'L' >= 'V' (the next character), it's not a subtraction case. So, we add the value of 'L' (50) to the result.
        - Result = 0 + 50 = 50
    - At index 1: s[1] = 'V'
        - Since 'V' < 'I' (the next character), it's a subtraction case. So, we subtract the value of 'V' (5) from the result.
        - Result = 50 - 5 = 45
    - At index 2: s[2] = 'I'
        - Since 'I' < 'I' (the next character), it's not a subtraction case. So, we add the value of 'I' (1) to the result.
        - Result = 45 + 1 = 46
    - At index 3: s[3] = 'I'
        - Since 'I' < 'V' (the next character), it's a subtraction case. So, we subtract the value of 'I' (1) from the result.
        - Result = 46 - 1 = 45

Final result: 45

So, the integer value of the Roman numeral "LVIII" is 45.
```
