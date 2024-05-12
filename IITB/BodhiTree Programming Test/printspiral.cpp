/*
                    Print Spiral
 n=3
 arr[3][3]
 
 00 01 02
 10 11 12
 20 21 22
 
 00 01 02 10 11 12 20 21 22
*/
#include <iostream>
using namespace std;

void printspiral(int arr[][100], int n){
    int top=0,bottom=n-1,left=0,right=n-1,direction=0;
    
    while(top<=bottom && left<=right){
        if(direction==0){ // left to right
            for(int i=left;i<=right;i++){
                cout<<arr[top][i];
            }
            top++;
        }else if(direction==1){ // top to down
            for(int i=top;i<=bottom;i++){
                cout<<arr[i][right];
            }
            right--;
        }else if(direction==2){ // right to left
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i];
            }
            bottom--;
        }else if(direction == 3){ // bottom to top
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left];
            }
            left++;
        }
        direction = (direction + 1)%4;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    printspiral(arr, n);
    
    return 0;
}