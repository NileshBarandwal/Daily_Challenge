class Solution {
public:
    string addBinary(string a, string b) {
        // Variables to track position and carry
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0; // This will store carry-over value
        string result = "";

        // Loop from the end of both strings
        while (i >= 0 || j >= 0 || carry > 0) {
            // Get the current digits (if they exist)
            int bitA = (i >= 0) ? a[i] - '0' : 0; // Convert char to int
            int bitB = (j >= 0) ? b[j] - '0' : 0;

            // Calculate sum and carry
            int sum = bitA + bitB + carry;
            carry = sum / 2; // New carry for the next iteration
            int currentBit = sum % 2; // Current binary result

            // Prepend the result (we are processing from right to left)
            result = to_string(currentBit) + result;

            // Move left
            i--;
            j--;
        }

        // Return the final result
        return result;
    }
};
