// 959. Regions Cut By Slashes

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = 4 * n * n; // Each cell has 4 sub-cells
        vector<int> parent(size);
        vector<int> rank(size, 0);

        // Initialize union-find
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }

        // Define find function for union-find
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        };

        // Define union function for union-find
        function<void(int, int)> union_sets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                if (rank[rootX] == rank[rootY]) {
                    ++rank[rootX];
                }
            }
        };

        // Helper function to get index for sub-cells
        auto getIndex = [&](int i, int j, int k) -> int {
            return (i * n + j) * 4 + k;
        };

        // Process each cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '/') {
                    union_sets(getIndex(i, j, 0), getIndex(i, j, 3));
                    union_sets(getIndex(i, j, 1), getIndex(i, j, 2));
                } else if (c == '\\') {
                    union_sets(getIndex(i, j, 0), getIndex(i, j, 1));
                    union_sets(getIndex(i, j, 2), getIndex(i, j, 3));
                } else { // c == ' '
                    union_sets(getIndex(i, j, 0), getIndex(i, j, 1));
                    union_sets(getIndex(i, j, 1), getIndex(i, j, 3));
                    union_sets(getIndex(i, j, 3), getIndex(i, j, 2));
                }

                // Connect with adjacent cells
                if (i + 1 < n) {
                    union_sets(getIndex(i, j, 2), getIndex(i + 1, j, 0));
                }
                if (j + 1 < n) {
                    union_sets(getIndex(i, j, 1), getIndex(i, j + 1, 3));
                }
            }
        }

        // Count unique roots
        unordered_set<int> unique_roots;
        for (int i = 0; i < size; ++i) {
            unique_roots.insert(find(i));
        }

        return unique_roots.size();
    }
};
