// 502. IPO

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Min-heap for capital requirements
        // In this declaration, greater<int> is a functor that ensures elements are stored in ascending order, making the smallest element the top priority.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCapitalHeap(projects.begin(), projects.end());
        
        // Max-heap for profits
        priority_queue<int> maxProfitHeap;
        
        while (k > 0) {
            // Move all affordable projects to the max-heap
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }
            
            // If there are no affordable projects, break
            if (maxProfitHeap.empty()) {
                break;
            }
            
            // Take the project with the maximum profit
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            
            --k;
        }
        
        return w;
    }
};