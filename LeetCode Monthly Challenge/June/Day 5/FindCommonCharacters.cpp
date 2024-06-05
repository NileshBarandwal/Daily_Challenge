// 1002. Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        map<char, int> s1;
        for(char ch : words[0]){
            s1[ch]++;
        }
        for(int i = 1;i<words.size();i++){
            map<char, int> wordcount;
            for(char ch : words[i]){
                wordcount[ch]++;
            }

            for(auto& [c,count] : s1){
                s1[c] = min(s1[c], wordcount[c]);
            }
        }

        for(const auto& [c,count] : s1){
            for(int i=0;i<count;i++){
                result.push_back(string(1,c));
            }
        }

        return result;
    }
};