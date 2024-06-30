// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    bool unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n + 1), parentB(n + 1), rankA(n + 1, 0), rankB(n + 1, 0);
        iota(parentA.begin(), parentA.end(), 0);
        iota(parentB.begin(), parentB.end(), 0);

        int usedEdges = 0;

        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (unite(parentA, rankA, edge[1], edge[2])) {
                    unite(parentB, rankB, edge[1], edge[2]);
                    usedEdges++;
                }
            }
        }

        // Process type 1 edges for Alice
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (unite(parentA, rankA, edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }

        // Process type 2 edges for Bob
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (unite(parentB, rankB, edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }

        // Check if both graphs are fully traversable
        int rootA = find(parentA, 1);
        int rootB = find(parentB, 1);

        for (int i = 2; i <= n; ++i) {
            if (find(parentA, i) != rootA || find(parentB, i) != rootB) {
                return -1;
            }
        }

        return edges.size() - usedEdges;
    }
};
