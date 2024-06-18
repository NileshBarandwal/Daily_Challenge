// 832. Flipping an Image
// Solution 2
// This version uses XOR (^ 1) to invert the bits directly during the flipping process, which can make the code slightly more efficient and compact.
// Prev solution is correct and effectively solves the problem. By applying the minor improvement mentioned, 
// the code becomes more concise while maintaining clarity and correctness.

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
                image[i][start] = image[i][end]^1;
                image[i][end] = temp^1;
                start++;
                end--;
            }
        }
        return image;
    }
};