#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> result;
       int row = matrix.size();
       int col = matrix[0].size();
       int e = row*col;
       bool right=true,left=false,up=false,down=false;
       int i=0,j=0;
       int top=0,leftboundary=0,bottom=row-1,rightboundry=col-1;
       while(result.size()<e){
           if(right){
               while(j<=rightboundry && result.size()<e){
                   result.push_back(matrix[i][j]);
                   j++;
               }
               j--;
               i++;
               top++;
               right = false;
               down = true;
           }else if(down){
               while(i<=bottom && result.size()<e){
                   result.push_back(matrix[i][j]);
                   i++;
               }
               i--;
               j--;
               rightboundry--;
               down = false;
               left = true;
           }else if(left){
               while(j>=leftboundary && result.size()<e){
                   result.push_back(matrix[i][j]);
                   j--;
               }
               j++;
               i--;
               bottom--;
               left = false;
               up = true;
           }else if(up){
               while(i>=top && result.size()<e){
                   result.push_back(matrix[i][j]);
                   i--;
               }
               i++;
               j++;
               up = false;
               right = true;
               leftboundary++;
           }
       }
       return result;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    
    for(int i : result){
        cout<<i<<" ";
    }
    
    return 0;
}
