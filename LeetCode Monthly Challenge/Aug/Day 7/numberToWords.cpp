// 273. Integer to English Words

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> belowHundred = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        vector<int> values = {1000000000, 1000000, 1000, 100, 1};
        vector<string> units = {" Billion", " Million", " Thousand", " Hundred", ""};

        string result;
        
        for (int i = 0; i < values.size(); ++i) {
            int unitValue = values[i];
            if (num >= unitValue) {
                int count = num / unitValue;
                num %= unitValue;
                
                if (unitValue >= 100) {
                    result += " " + numberToWords(count) + units[i];
                } else {
                    if (count >= 20) {
                        result += " " + belowHundred[count / 10];
                        if (count % 10) result += " " + belowTen[count % 10];
                    } else if (count >= 10) {
                        result += " " + belowTwenty[count - 10];
                    } else if (count > 0) {
                        result += " " + belowTen[count];
                    }
                }
            }
        }
        
        // Trim leading space
        if (!result.empty() && result[0] == ' ') {
            result = result.substr(1);
        }
        
        return result;
    }
};
