class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // If the digit is not 9, simply increment it
                digits[i]++;
                return digits; // Early return, no carry-over
            } else {
                // If the digit is 9, set it to 0 (carry-over)
                digits[i] = 0;
            }
        }
        
        // If all digits were 9, then we have a carry-over to a new most significant digit
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};