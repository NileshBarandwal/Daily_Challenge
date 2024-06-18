// 826. Most Profit Assigning Work
// Solution 1
// Vector

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Combine difficulty and profit and sort the jobs by difficulty
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        // for (const auto& job : jobs) {
        //     cout << "(" << job.first << ", " << job.second << ")" << endl;
        // }
        
        int maxProfit = 0, bestProfit = 0, j = 0;
        
        // Iterate over each worker
        for (int ability : worker) {
            // Update the best_profit for current ability
            while (j < jobs.size() && jobs[j].first <= ability) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
            }
            // Accumulate the profit for this worker
            maxProfit += bestProfit;
        }
        
        return maxProfit;
    }
};