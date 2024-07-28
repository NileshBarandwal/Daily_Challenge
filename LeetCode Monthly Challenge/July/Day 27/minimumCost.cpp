// 2976. Minimum Cost to Convert String I

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        if (n != target.size()) return -1;
        
        // Create graph with 26 nodes (a-z)
        vector<vector<pair<int, int>>> graph(26);
        
        // Populate the graph with given transformations
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u].emplace_back(v, cost[i]);
        }
        
        // Function to find the shortest path from any character to any other character using Dijkstra's algorithm
        auto dijkstra = [&](int src) {
            vector<int> dist(26, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, src);
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > dist[u]) continue;
                
                for (auto &[v, w] : graph[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            
            return dist;
        };
        
        // Precompute shortest paths for all characters
        vector<vector<int>> min_cost(26);
        for (int i = 0; i < 26; ++i) {
            min_cost[i] = dijkstra(i);
        }
        
        // Calculate the total minimum cost to transform source to target
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            int src_char = source[i] - 'a';
            int tgt_char = target[i] - 'a';
            int cost = min_cost[src_char][tgt_char];
            if (cost == INT_MAX) return -1;  // transformation not possible
            total_cost += cost;
        }
        
        return total_cost;
    }
};
