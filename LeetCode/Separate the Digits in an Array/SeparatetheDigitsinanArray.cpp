// 2553. Separate the Digits in an Array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            // Vector n gets reset here for each number in nums
            vector<int> n;
            // Extract digits and store in vector n
            while (num != 0) {
                n.push_back(num % 10);
                num = num / 10;
            }
            // Reverse the vector n to get the digits in original order
            reverse(n.begin(), n.end());
            // Insert all elements of n into result
            //(position where to insert, start, end)
            result.insert(result.end(), n.begin(), n.end());
        }
        return result;
    }
};