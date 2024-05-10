/********
Sample Input 1: 309
Sample Output 1: 5
Explanation: The binary representation is: 100110101 . The longest consecutive alternating
sequence of 1’s and 0’s is 10101 .
Sample Input 2: 554
Sample Output 2: 7
Explanation: The binary representation is: 1000101010 . The longest consecutive alternating
sequence of 1’s and 0’s is 0101010 .
********/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a;
    vector<int> arr;
    int max=1,current=1;
    cin>>a;
    while(a){
        arr.push_back(a%2);
        a=a/2;
    }
    reverse(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            current++;
        }else{
            if(current>max){
                max=current;
            }
            current=1;
        }
    }
    
    if(current>max){
        max=current;
    }
    cout<<max;
    return max;
}