// 2053. Kth Distinct String in an Array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        
        // Count the occurrences of each string
        for (const string& str : arr) {
            countMap[str]++;
        }
        
        // Collect distinct strings in the order they appear
        vector<string> distinctStrings;
        for (const string& str : arr) {
            if (countMap[str] == 1) {
                distinctStrings.push_back(str);
            }
        }
        
        // Return the kth distinct string if it exists
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        }
    }
};