class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> s1;
        for(int s : nums1){
            s1[s]++;
        }   

        for(int num : nums2){
            if(s1[num]>0){
                result.push_back(num);
                s1[num]--;
            }
        }

         return result;
    }
};