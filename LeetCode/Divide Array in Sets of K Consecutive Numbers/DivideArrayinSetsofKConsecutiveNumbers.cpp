// 1296. Divide Array in Sets of K Consecutive Numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> s1;
        for(int ch : nums){
            s1[ch]++;
        }
        while(!(s1.empty())){
            auto it = s1.begin();
            int firstNumber = it->first;
            for(int i=0;i<k;i++){
                if(s1.find(firstNumber+i) == s1.end()){
                    return false;
                }
                if(--s1[firstNumber+i]==0){
                    s1.erase(firstNumber+i);
                }
                ++it;
            }
        }
        return true;
    }
};