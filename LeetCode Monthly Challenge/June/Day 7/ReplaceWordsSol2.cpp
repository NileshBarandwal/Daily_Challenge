// June || Day 7 || 648. Replace Words || Optimized Solution

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string result;
        string word;
        sentence += ' ';  // Add a space at the end to handle the last word
        for(char ch : sentence){
            if(ch != ' '){
                word+=ch;
            }else{
                // Use temp string to store original word
                string replacement = word;
                for(const string& dirWord : dictionary){
                    // Trim out first char equal to size of dictionary and compare if equal
                    // check for min size bet original and dictonary size
                    if(word.substr(0, dirWord.size()) == dirWord && dirWord.size()<replacement.size()){
                        replacement = dirWord;
                    }
                }

                // Put empty or space after every word
                if(!(result.empty())){
                    result+=' ';
                }
                result+=replacement;
                // Important to clear before traversing to next word
                word.clear();
            }
        }
        return result;
        }
};