// 1514. Path with Maximum Probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        // Max-heap priority queue
        priority_queue<pair<double, int>> pq;
        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;
        pq.emplace(1.0, start_node);
        
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            // If we've reached the end node
            if (node == end_node) {
                return prob;
            }
            
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > probabilities[neighbor]) {
                    probabilities[neighbor] = newProb;
                    pq.emplace(newProb, neighbor);
                }
            }
        }
        
        // If end node is unreachable
        return 0.0;
    }
};