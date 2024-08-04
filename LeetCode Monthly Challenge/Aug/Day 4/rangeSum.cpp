// 1508. Range Sum of Sorted Subarray Sums

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1'000'000'007;
        vector<long> subarraySums;
        
        // Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }
        
        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());
        
        // Compute the sum from index left to right
        long result = 0;
        for (int i = left - 1; i < right; ++i) {
            result = (result + subarraySums[i]) % MOD;
        }
        
        return result;
    }
};