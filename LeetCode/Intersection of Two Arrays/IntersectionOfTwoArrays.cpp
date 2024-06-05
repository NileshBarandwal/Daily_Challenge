// 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i : nums1){
           s1.insert(i);
        }
        for(int i : nums2){
            s2.insert(i);
        }

        for(const int& num1 : s1){
            for(const int& num2 : s2){
                if(num1 == num2){
                    result.push_back(num2);
                }
            }
        }
        return result;
    }
};