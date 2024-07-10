// 1701. Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int chefAvailableTime = 0;
        
        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];
            
            if (chefAvailableTime < arrivalTime) {
                chefAvailableTime = arrivalTime;
            }
            
            chefAvailableTime += cookingTime;
            totalWaitingTime += (chefAvailableTime - arrivalTime);
        }
        
        return (double) totalWaitingTime / customers.size();
    }
};