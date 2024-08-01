// 2678. Number of Senior Citizens

class Solution {
public:
    int countSeniors(vector<string>& details) {
        vector<int> ages;
        for(string detail : details){
            string age = detail.substr(11, 2);
            int a = stoi(age);
            if(a>60){
                ages.push_back(a);
            }
        }
        return ages.size();
    }
};