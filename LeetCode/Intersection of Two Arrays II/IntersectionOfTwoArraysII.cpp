class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> s1;
        for(int s : nums1){
            s1[s]++;
        }

        map<int, int> s2;
         for(int i : nums2){
            s2[i]++;
         }

         for(const auto& [c,count]: s1){
            s1[c] = min(s1[c],s2[c]);  
         }

         for(const auto& [c,count] : s1){
            for(int i=0;i<count;i++){
                result.push_back(c);
            }
        }

         return result;
    }
};