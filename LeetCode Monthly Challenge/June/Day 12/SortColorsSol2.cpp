// 75. Sort Colors
// Solution 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> sorted;
        // Count the occurrences of each color
        for (int num : nums) {
            sorted[num]++;
        }
        // Reconstruct the sorted array
        int index = 0;
        for (auto& [num, count] : sorted) {
            while (count > 0) {
                nums[index++] = num;
                count--;
            }
        }
    }
};