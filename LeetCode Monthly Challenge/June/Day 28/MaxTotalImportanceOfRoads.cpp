// 2285. Maximum Total Importance of Roads
// Uses simple vectors and sorting, which is straightforward and easy to understand.

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       // Step 1: Count the number of roads each city is connected to
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Step 2: Sort cities by the number of roads they are connected to
        vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        // Step 3: Assign values based on the sorted order
        vector<int> value(n);
        for (int i = 0; i < n; ++i) {
            value[cities[i]] = n - i;
        }
        
        // Step 4: Calculate the total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }
        
        return totalImportance; 
    }
};