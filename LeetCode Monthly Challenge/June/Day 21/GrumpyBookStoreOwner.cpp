// 1052. Grumpy Bookstore Owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Calculate the number of satisfied customers without using the technique
        int totalSatisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            }
        }

        // Use sliding window to find the maximum number of additional customers we can satisfy
        int additionalSatisfied = 0, maxAdditionalSatisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1) {
                additionalSatisfied += customers[i];
            }
            // When the window exceeds 'minutes' size, slide the window
            if (i >= minutes && grumpy[i - minutes] == 1) {
                additionalSatisfied -= customers[i - minutes];
            }
            // Update the maximum additional satisfied customers we can get
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
        }

        return totalSatisfied + maxAdditionalSatisfied;
    }
};
