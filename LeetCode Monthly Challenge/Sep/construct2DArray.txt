// 2022. Convert 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the transformation is possible
        if (original.size() != m * n) {
            return {}; // Return an empty vector if it's not possible
        }
        
        // Initialize the 2D array
        vector<vector<int>> arr(m, vector<int>(n));
        
        int k = 0;
        
        // Fill the 2D array with elements from the original array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = original[k];
                k++;
            }
        }
        
        return arr;
    }
};