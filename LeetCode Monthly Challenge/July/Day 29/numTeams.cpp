// 1395. Count Number of Teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        
        // Iterate through all possible triplets
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Check the conditions for a valid team
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) || 
                        (rating[i] > rating[j] && rating[j] > rating[k])) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};