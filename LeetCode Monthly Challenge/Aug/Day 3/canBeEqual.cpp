// 1460. Make Two Arrays Equal by Reversing Subarrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> targetcount, arrcount;
        for(int num:target){
            targetcount[num]++;
        }

        for(int num:arr){
            arrcount[num]++;
        }

        return targetcount == arrcount;
    }
};