// 1380. Lucky Numbers in a Matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> intersection;
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        vector<int> minrow;
        vector<int> maxcol;

        // find min from each row
        for(int i=0;i<matrix.size();i++){
            for(int num: matrix[i]){
                min_num = min(min_num, num);
            }
                minrow.push_back(min_num);
                min_num = INT_MAX;
        }

        for (int col = 0; col < matrix[0].size(); ++col) {
                for (int row = 0; row < matrix.size(); ++row) {
                    max_num = max(max_num, matrix[row][col]);
                }
                maxcol.push_back(max_num);
                max_num = INT_MIN;
            }

        for(int numA : minrow){
            for(int numB : maxcol){
                if(numA == numB){
                    intersection.push_back(numA);
                    break;
                }
            }
        }
        
        return intersection;
    }
};