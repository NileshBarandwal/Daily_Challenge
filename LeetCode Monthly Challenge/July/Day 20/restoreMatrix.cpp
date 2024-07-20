// 1605. Find Valid Matrix Given Row and Column Sums

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Calculate the value for the current cell
                int value = min(rowSum[i], colSum[j]);
                
                // Assign value to the cell
                matrix[i][j] = value;
                
                // Update rowSum and colSum
                rowSum[i] -= value;
                colSum[j] -= value;
            }
        }

        return matrix;
    }
};