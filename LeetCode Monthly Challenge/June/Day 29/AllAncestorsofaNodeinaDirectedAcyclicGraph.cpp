// 2192. All Ancestors of a Node in a Directed Acyclic Graph

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ancestors(n);

        // Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Function to perform BFS and find ancestors
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            vector<bool> visited(n, false);
            
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int ancestor : adj[node]) {
                    if (!visited[ancestor]) {
                        q.push(ancestor);
                        visited[ancestor] = true;
                        ancestors[i].push_back(ancestor);
                    }
                }
            }

            // Sort the ancestors list to maintain order
            sort(ancestors[i].begin(), ancestors[i].end());
        }

        return ancestors;
    }
};