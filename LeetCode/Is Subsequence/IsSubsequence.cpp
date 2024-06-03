class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int i=0,j=0;
        for(char ch : t){
            if(i<slen && ch==s[i]){
                i++;
            }
        }
        if((slen-i)!=0){
            return false;
        }else{
            return true;
        }
    }
};