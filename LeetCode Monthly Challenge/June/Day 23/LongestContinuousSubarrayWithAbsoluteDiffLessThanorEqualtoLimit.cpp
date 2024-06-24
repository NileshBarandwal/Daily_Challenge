// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0;
        int maxLength = 0;

        while (right < n) {
            // Maintain the maximums in maxDeque (descending order)
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            // Maintain the minimums in minDeque (ascending order)
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            // Check the difference condition
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (maxDeque.front() < left)
                    maxDeque.pop_front();
                if (minDeque.front() < left)
                    minDeque.pop_front();
            }

            // Update maxLength
            maxLength = max(maxLength, right - left + 1);

            // Move the right pointer
            right++;
        }

        return maxLength;
    }
};
