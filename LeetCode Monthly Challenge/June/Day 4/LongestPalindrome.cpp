// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> pal;
        for(char ch : s){
            pal[ch]++;
        }

        int length=0;
        bool isodd=false;
        for(const auto& pair : pal){
            if(pair.second%2==0){
                length+=pair.second;
            }else{
                length+=pair.second-1;
                isodd = true;
            }
        }

        if(isodd){
            length+=1;
        }
        return length;
    }
};