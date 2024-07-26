// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int minReachableCities = INT_MAX;
        int resultCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities < minReachableCities || (reachableCities == minReachableCities && i > resultCity)) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};
