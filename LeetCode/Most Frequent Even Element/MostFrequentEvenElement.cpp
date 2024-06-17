// 2404. Most Frequent Even Element

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> s1;
        for(int num: nums){
            if(num%2==0){
                s1[num]++;
            }
        }
        if(s1.empty()){
            return -1;
        }

        int mostFrequent = -1;
        int maxCount = 0;
        
        for (auto& [key, value] : s1) {
            if (value > maxCount || (value == maxCount && key < mostFrequent)) {
                maxCount = value;
                mostFrequent = key;
            }
        }
        
        return mostFrequent;
    }
};