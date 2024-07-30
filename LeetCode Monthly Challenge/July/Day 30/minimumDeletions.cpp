// 1653. Minimum Deletions to Make String Balanced

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count_a = 0, count_b = 0;
        
        // Count total number of 'a's and 'b's
        for (char c : s) {
            if (c == 'a') count_a++;
            else count_b++;
        }
        
        int left_b = 0, right_a = count_a;
        int min_deletions = right_a; // Initial case: remove all 'a's
        
        // Traverse through the string
        for (char c : s) {
            if (c == 'a') right_a--; // One less 'a' to the right
            else left_b++; // One more 'b' to the left
            
            // Calculate the minimum deletions needed to make string balanced
            min_deletions = min(min_deletions, left_b + right_a);
        }
        
        return min_deletions;
    }
};