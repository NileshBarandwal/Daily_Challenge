// 664. Strange Printer

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Base case: single character substrings
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Compute dp values for substrings of length > 1
        for (int len = 2; len <= n; ++len) { // len is the length of the substring
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // end index of the substring
                // If the entire substring consists of the same character
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                }
                // Try all possible partitions of the substring
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
