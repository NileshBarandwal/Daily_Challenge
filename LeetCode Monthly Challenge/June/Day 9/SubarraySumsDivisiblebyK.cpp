// 974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;  // Initial count for subarrays that directly sum to a multiple of k
        int count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = prefixSum % k;

            // Adjust for negative remainders
            if (remainder < 0) {
                remainder += k;
            }

            // Count subarrays based on the current remainder
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            // Update the count of the current remainder
            remainderCount[remainder]++;
        }

        return count;
    }
};