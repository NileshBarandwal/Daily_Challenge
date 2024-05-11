/******************************************************************************

Q4) Consider a 2D-array with dimensions m*n . We will use the notation arr[i][j] to refer to
the element at the i th

row and j th column of the array arr . For a positive input number k ,
perform the following simulation k times: (12 Marks)
Simulation : For each element at i and j , replace arr[i][j] by sum of its neighbors divided
by the number of neighbors (integer division). Two elements arr[i][j] and arr[i’][j’]
are neighbours if |i - i’| + |j - j’| = 1 .
Note that the corner element will have only two neighbors and the non-corner elements on the
border will have only 3 neighbors.
Input format: The first line consists of 3 integers m, n, k . The next lines contain m x n
integers in row-major order .
The output should be just one line containing m x n elements also in row-major order.
Hint: You will have to use two 2D arrays.
E.g.
3 3 2 (3x3 is m and n, and k=2)
1 2 3
4 5 6
7 8 9
After the first simulation:
3 3 4
4 5 5
6 7 7
After the second iteration:
3 4 4
4 4 5
5 6 6
So, output is: 3 4 4 4 4 5 5 6 6
Sample Input:
3 3 2
1 2 3
4 5 6
7 8 9
Sample Output
3 4 4 4 4 5 5 6 6

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int new_arr[m][n];
    
    for(int t=0;t<k;++t){
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int count=0;
                int sum=0;
                if(i>0){ // Top
                    sum+=arr[i-1][j];
                    count++;
                }
                if(i<m-1){ // Bottom
                    sum+=arr[i+1][j];
                    count++;
                }
                if(j>0){ // Left
                    sum+=arr[i][j-1];
                    count++;
                }
                if(j<n-1){
                    sum+=arr[i][j+1];
                    count++;
                }
                new_arr[i][j] = sum / count;
            }
        }
        
        // Copy back to original array
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                arr[i][j] = new_arr[i][j];
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
            
            if(j<n-1){
            cout<<" ";
        }
        }
        
        if(i<m-1){
            cout<<" ";
        }
    }

    return 0;
}
