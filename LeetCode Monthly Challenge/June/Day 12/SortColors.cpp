// 75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> sorted;
        vector<int> sort;
        for(int num : nums){
            sorted[num]++;
        }
        for(auto& [num, count]:sorted){
            while(count>0){
                sort.push_back(num);
                --count;
            }
        }
        nums=sort;
    }
};