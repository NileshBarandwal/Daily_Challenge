// 1568. Minimum Number of Days to Disconnect Island

class Solution {
public:
    // Directions for moving in 4 directions (up, down, left, right)
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    // Function to count the number of islands using BFS
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dir[k][0];
                            int ny = y + dir[k][1];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && grid[nx][ny] == 1) {
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        // Step 1: If the grid is already disconnected, return 0
        if (countIslands(grid) != 1) return 0;

        int m = grid.size();
        int n = grid[0].size();

        // Step 2: Check if we can disconnect by changing one land cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1; // Revert the change
                }
            }
        }

        // Step 3: If it can't be disconnected by changing one cell, it takes 2 days
        return 2;
    }
};
