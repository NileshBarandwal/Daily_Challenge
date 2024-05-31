class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> occurance; 
        vector<int> rs;

        for(int num : nums){
            occurance[num]++;
        }

        for (int num : nums) {
            if (occurance[num] == 1) {
                rs.push_back(num);
            }
        }
        return rs;
    }
};