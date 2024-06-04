// 242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
     unordered_map<char, int> ch1;
     unordered_map<char, int> ch2;
     for(char i : s){
        ch1[i]++;
     }
     for(char i : t){
        ch2[i]++;
     }
     if(ch1==ch2){
        return true;
     }else{
        return false;
     }   
    }
};