// 1929. Concatenation of Array
// Solution 1

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.begin(),nums.end());
	// (position where to insert, start, end)
        result.insert(result.end(),nums.begin(),nums.end());
        return result;
    }
};