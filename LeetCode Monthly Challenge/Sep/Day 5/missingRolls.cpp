// 2028. Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalRolls = n + m;
        int totalSumRequired = totalRolls * mean;
        int sumKnownRolls = accumulate(rolls.begin(), rolls.end(), 0);
        int sumMissingRolls = totalSumRequired - sumKnownRolls;
        
        // Check if the sumMissingRolls is feasible
        if (sumMissingRolls < n || sumMissingRolls > 6 * n) {
            return {};
        }
        
        vector<int> missing(n, 1); // Initialize all missing rolls to 1
        sumMissingRolls -= n; // We have already assumed n rolls of 1
        
        // Distribute the remaining sum to the rolls
        for (int i = 0; i < n; ++i) {
            int add = min(5, sumMissingRolls); // Add the minimum of 5 or remaining sum
            missing[i] += add; // Add to the current roll
            sumMissingRolls -= add; // Decrease the remaining sum
        }
        
        return missing;
    }
};