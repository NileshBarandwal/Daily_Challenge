// 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long totalChalk = 0;
        
        // Calculate the total chalk required for one full cycle
        for (int i = 0; i < n; ++i) {
            totalChalk += chalk[i];
        }
        
        // Determine how many full cycles of students we can complete with k pieces of chalk
        k %= totalChalk;
        
        // Find the index where the chalk will run out
        for (int i = 0; i < n; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // This line should never be reached
    }
};