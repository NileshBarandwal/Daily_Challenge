// 840. Magic Squares In Grid

class Solution {
public:
    vector<vector<int>> magicSquares = {
        {8, 1, 6, 3, 5, 7, 4, 9, 2}, 
        {6, 1, 8, 7, 5, 3, 2, 9, 4}, 
        {4, 9, 2, 3, 5, 7, 8, 1, 6}, 
        {2, 9, 4, 7, 5, 3, 6, 1, 8}, 
        {8, 3, 4, 1, 5, 9, 6, 7, 2}, 
        {4, 3, 8, 9, 5, 1, 2, 7, 6}, 
        {6, 7, 2, 1, 5, 9, 8, 3, 4}, 
        {2, 7, 6, 9, 5, 1, 4, 3, 8}
    };

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        if (row < 3 || col < 3) {
            return 0;
        }

        for (int i = 0; i <= row - 3; ++i) {
            for (int j = 0; j <= col - 3; ++j) {
                vector<int> subgrid = {
                    grid[i][j], grid[i][j+1], grid[i][j+2],
                    grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                    grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]
                };

                for (const auto& magic : magicSquares) {
                    if (subgrid == magic) {
                        ++count;
                        break;
                    }
                }
            }
        }

        return count;
    }
};
