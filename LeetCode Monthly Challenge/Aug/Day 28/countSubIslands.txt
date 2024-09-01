// 1905. Count Sub Islands

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;

        // Lambda function for DFS
        auto dfs = [&](int x, int y, auto&& dfs_ref) -> bool {
            if (x < 0 || y < 0 || x >= m || y >= n || grid2[x][y] == 0)
                return true;

            bool isSubIsland = grid1[x][y] == 1;
            grid2[x][y] = 0; // Mark as visited

            // Visit all four directions
            isSubIsland &= dfs_ref(x + 1, y, dfs_ref);
            isSubIsland &= dfs_ref(x - 1, y, dfs_ref);
            isSubIsland &= dfs_ref(x, y + 1, dfs_ref);
            isSubIsland &= dfs_ref(x, y - 1, dfs_ref);

            return isSubIsland;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (dfs(i, j, dfs)) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};