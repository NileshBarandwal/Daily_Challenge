class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(),nums.end());
        int maxk = -1;
        for(int num:nums){
            if(num>0 && numset.find(-num) != numset.end()){
                maxk = max(maxk,num);
            }
        }
        return maxk;
    }
};