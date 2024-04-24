class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if(strs.empty())
         {
            return "";
         }
         
         string prefix = strs[0];

         for(const auto& str: strs){
            while(str.find(prefix)!=0){
                prefix = prefix.substr(0, prefix.length()-1);
                if (prefix.empty()){
                    return "";
                }
            }
         }
         return prefix;
    }
};