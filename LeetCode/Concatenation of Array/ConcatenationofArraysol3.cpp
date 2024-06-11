// 1929. Concatenation of Array
// Solution 3

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
	// Instead of storing nums into new vector and adding elements at the end, 
	// directly start adding elements at end of existing vector nums.
       	nums.insert(nums.end(),nums.begin(),nums.end());
        return nums;
    }
};