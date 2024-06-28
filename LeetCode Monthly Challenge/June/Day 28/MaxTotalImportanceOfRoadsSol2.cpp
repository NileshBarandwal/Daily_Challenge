// 2285. Maximum Total Importance of Roads
// Uses a multimap, which is a bit more complex but provides built-in sorting functionality.

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       // Step 1: Count the number of roads each city is connected to
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Step 2: Use a multimap to sort cities by their degree in descending order
        multimap<int, int, greater<int>> sortedCities;
        for (int i = 0; i < n; ++i) {
            sortedCities.insert({degree[i], i});
        }
        
        // Step 3: Assign values based on the sorted order
        vector<int> value(n);
        int currentValue = n;
        for (const auto& entry : sortedCities) {
            value[entry.second] = currentValue--;
        }
        
        // Step 4: Calculate the total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }
        
        return totalImportance; 
    }
};