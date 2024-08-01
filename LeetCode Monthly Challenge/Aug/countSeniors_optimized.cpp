// 2678. Number of Senior Citizens
// Optimized Version

// why wrote const string& and whats the problem with previous version

// Using const string& instead of string in the loop has a couple of advantages:

// Avoids Unnecessary Copying: When you use string detail in the loop, a copy of each string from the details vector
// is created. This copying process is unnecessary and can be avoided by using a reference.

// Const Correctness: Adding const indicates that the referenced string will not be modified within the loop. This
// can prevent accidental modifications and can also help the compiler with optimizations.

// ** Also string can be directly trim and converted to integer.
// ** No need of storing ages instead we can directly count them and return this value.

class Solution {
public:
    int countSeniors(const vector<string>& details) {
        int count = 0;
        for (const string& detail : details) {
            int age = stoi(detail.substr(11, 2));
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};
