// 2540. Minimum Common Value

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        // Given that the input arrays are sorted, 
        // we can leverage the "two-pointer" technique to find the smallest common element efficiently.

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // Found the smallest common element
            } else if (nums1[i] < nums2[j]) {
                i++; // Move the pointer in nums1
            } else {
                j++; // Move the pointer in nums2
            }
        }

        return -1; // No common element found
    }
};