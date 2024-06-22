// 1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // continuous subarray is called nice 
         int n = nums.size();
    int odd_count = 0;
    int start = 0;
    int result = 0;
    int subarray_start_count = 0;

    for (int end = 0; end < n; ++end) {
        if (nums[end] % 2 != 0) {
            odd_count++;
        }

        while (odd_count > k) {
            if (nums[start] % 2 != 0) {
                odd_count--;
            }
            start++;
            subarray_start_count = 0;
        }

        if (odd_count == k) {
            int subarray_start_temp = start;
            while (subarray_start_temp <= end && nums[subarray_start_temp] % 2 == 0) {
                subarray_start_temp++;
            }
            subarray_start_count = subarray_start_temp - start + 1;
        }

        result += subarray_start_count;
    }

    return result;
    }
};