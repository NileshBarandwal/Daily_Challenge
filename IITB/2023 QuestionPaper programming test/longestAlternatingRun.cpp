/******************************************************************************

Sample Input 1: 309
Sample Output 1: 5
Explanation: The binary representation is: 100110101 . The longest consecutive alternating
sequence of 1’s and 0’s is 10101 .

Sample Input 2: 554
Sample Output 2: 7
Explanation: The binary representation is: 1000101010 . The longest consecutive alternating
sequence of 1’s and 0’s is 0101010 .

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void DecimalToBinary(int decimal) {
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            arr.push_back(0);
        } else {
            arr.push_back(1);
        }
        decimal /= 2;  // Update to avoid infinite loop
    }
}

void printbinary(){
    // Print the array in backward direction
    for (int i = arr.size() - 1; i >= 0; --i) {  // Loop from the end to the start
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int longestAlternatingRun(){
    int current_length=1;
    int max_length=1;
    
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            current_length++;
        }else
        {
            if(current_length>max_length){
                max_length=current_length;
            }
        current_length=1;
        }
    }
    
    if(current_length>max_length){
        max_length = current_length;
    }
    
    return max_length;
}

int main() {
    int decimal;
    cin >> decimal;
    
    DecimalToBinary(decimal);
    printbinary();
    
    int longest_run = longestAlternatingRun();  // Find the longest alternating run
    cout<<longest_run << endl;  // Output the result
    
    return 0;
}
