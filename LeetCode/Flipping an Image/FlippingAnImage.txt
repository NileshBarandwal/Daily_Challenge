// 832. Flipping an Image
// Solution 1

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // 1 1 0
        // 1 0 1
        // 0 0 0
        // flipping [1,1,0] horizontally results in [0,1,1].
        // 0 1 1
        // 1 0 1
        // 0 0 0
        // flipping [1,1,0] horizontally results in [0,1,1]. 0 is replaced by 1, and each 1 is replaced by 0.
        // 1 0 0
        // 0 1 0
        // 1 1 1

        for(int i=0;i<image.size();i++){
            int start=0, end=image[i].size()-1;
            while(start<=end){
                int temp = image[i][start];
                image[i][start] = image[i][end];
                image[i][end] = temp;
                start++;
                end--;
            }
            for(int j=0;j<image[i].size();j++){
                if(image[i][j] == 0){
                    image[i][j] = 1;
                }else{
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
};