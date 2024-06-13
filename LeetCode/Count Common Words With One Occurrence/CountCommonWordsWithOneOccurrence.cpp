// 2085. Count Common Words With One Occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int result=0;
        unordered_map<string, int> s1, s2;
        for(string ch : words1){
            s1[ch]++;
        }

        for(string ch : words2){
            s2[ch]++;
        }

         // Check the counts directly
        for (const auto& [str, count] : s1) {
            if (count == 1 && s2[str] == 1) {
                result++;
            }
        }

        return result;
    }
};