// June || Day 10 || 1051. Height Checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // if f(a) >= f(b) for all a > b
        // For example, 1, 3, 3, 6, 8, 9 are in non-decreasing order, 
        // as every next element is greater than or equal to (in case of 3) 
        // but not less than the previous one.
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int count=0;
        for(int i = 0; i<heights.size();i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
        return count;
    }
};