/******************************************************************************

                              2D Array Multiplication

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int a,sum;
    int A[100][100];
    int B[100][100];
    int C[100][100];
    cin>>a;
    
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>B[i][j];
        }
    }
    
    for(int k=0;k<a;k++){ // A Row
        
        // B Array        
        for(int i=0;i<a;i++){ // Row
            for(int j=0;j<a;j++){ //left to right
                sum+= A[k][j]*B[i][j];
                if(j==a-1){
                    C[k][i]=sum;
                    sum=0;
                }
            }
        }    
    }
    
    // Print Output
    
        for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
