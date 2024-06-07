// June || Day 7 || 648. Replace Words

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
       vector<string> s1;
        string s;
        
        // Split the sentence into words
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] != ' ') {
                s += sentence[i];
            } else {
                s1.push_back(s);
                s = "";
            }
        }
        if (!s.empty()) {
            s1.push_back(s);
        }

        // Replace words with dictionary entries
        vector<string> s2;
        for (int i = 0; i < s1.size(); ++i) {
            string word = s1[i];
            string replacement = word;
            for (int j = 0; j < dictionary.size(); ++j) {
                string dictWord = dictionary[j];
                if (word.substr(0, dictWord.size()) == dictWord) {
                    if (replacement.size() > dictWord.size()) {
                        replacement = dictWord;
                    }
                }
            }
            s2.push_back(replacement);
        }

        // Create the result string
        string result;
        for (int i = 0; i < s2.size(); ++i) {
            if (i != 0) {
                result += " ";
            }
            result += s2[i];
        }

        return result;
        }
};