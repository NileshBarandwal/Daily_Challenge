// 1945. Sum of Digits of String After Convert

class Solution {
public:
    int getLucky(string s, int k) {
        // Convert string to integer
        string numStr = "";
        for (char c : s) {
            int digit = c - 'a' + 1;
            numStr += to_string(digit);
        }
        
        // Perform k transformations
        for (int i = 0; i < k; ++i) {
            int sum = 0;
            for (char digit : numStr) {
                sum += digit - '0';
            }
            numStr = to_string(sum);
        }
        
        // Convert resulting string back to integer
        return stoi(numStr);
    }
};