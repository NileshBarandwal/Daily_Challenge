// 1248. Count Number of Nice Subarrays
// SOlution 2

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // continuous subarray is called nice 
         int n = nums.size();
        int oddCount = 0;
        int result = 0;
        int left = 0;
        int count = 0;
        
        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
                count = 0;
            }
            
            while (oddCount == k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                count++;
                left++;
            }
            
            result += count;
        }
        
        return result;
    }
};