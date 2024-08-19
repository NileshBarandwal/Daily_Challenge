// 650. 2 Keys Keyboard

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0; // No operations needed if n is 1
        
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i; // Maximum case where you only use paste operations (1 + 1 + 1 + ...)
            for (int j = 1; j <= i / 2; ++j) {
                if (i % j == 0) { // j is a factor of i
                    dp[i] = min(dp[i], dp[j] + (i / j));
                }
            }
        }
        
        return dp[n];
    }
};
