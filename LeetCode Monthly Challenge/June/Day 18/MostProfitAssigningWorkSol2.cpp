// 826. Most Profit Assigning Work
// Solution 2
// Map

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> jobs;
        for(int i=0;i<difficulty.size();i++){
            jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }

        // for(const auto& job : jobs){
        //     cout<<"("<<job.first<<","<<job.second<<")"<<endl;
        // }

        sort(worker.begin(), worker.end());

        auto it = jobs.begin();

        int maxprofit = 0, bestprofit = 0, j=0;

        for(int ability:worker){
            while(it!=jobs.end() && it->first <= ability){
                bestprofit = max(bestprofit, it->second);
                ++it;
            }
            maxprofit+=bestprofit;
        }
        
        return maxprofit;
    }
};