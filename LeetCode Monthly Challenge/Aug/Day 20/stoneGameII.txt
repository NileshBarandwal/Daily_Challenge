// 1140. Stone Game II

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][m] stores the maximum number of stones the current player can collect starting from pile i with max X allowed as m
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        // suffixSum[i] stores the sum of stones from pile i to the end
        vector<int> suffixSum(n, 0);
        
        // Calculate suffix sums
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // Fill dp table
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    // If the player can take all remaining piles
                    dp[i][m] = suffixSum[i];
                } else {
                    // Evaluate the best option for picking 1 to 2*m piles
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        
        // The result is the maximum stones Alice can collect starting from index 0 with M = 1
        return dp[0][1];
    }
};
