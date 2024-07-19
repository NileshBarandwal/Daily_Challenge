// 1380. Lucky Numbers in a Matrix
// Solution 2
// Optimized

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> intersection;
        vector<int> minRow;
        vector<int> maxCol(matrix[0].size(), INT_MIN);

        // Find min from each row and populate minRow
        for(const auto& row : matrix) {
            int min_num = INT_MAX;
            for(int num : row) {
                min_num = min(min_num, num);
            }
            minRow.push_back(min_num);
        }

        // Find max from each column and populate maxCol
        for (int col = 0; col < matrix[0].size(); ++col) {
            for (int row = 0; row < matrix.size(); ++row) {
                maxCol[col] = max(maxCol[col], matrix[row][col]);
            }
        }

        // Find intersection of minRow and maxCol
        for(int numA : minRow) {
            for(int numB : maxCol) {
                if(numA == numB) {
                    intersection.push_back(numA);
                    break;
                }
            }
        }
        
        return intersection;
    }
};