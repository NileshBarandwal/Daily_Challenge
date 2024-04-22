/******************************************************************************

Output format: A single number.
The number equals the sum of the product of all possible pairs a_i and a_j such that i<j .
a1*a2 + a1*a3 + ... + a1*an + a2*a3 + a2*a4 + ... + a(n-1)*an
Sample input:
5
1 2 3 4 5
Sample Output :
85
Explanation:
1*2 + 1*3 + 1*4 + 1*5 + 2*3 + 2*4 + 2*5 + 3*4 + 3*5 + 4*5

*******************************************************************************/

#include <iostream>
using namespace std;

/*
Sample input:
5
1 2 3 4 5
Sample Output :
85
Explanation:
1*2 + 1*3 + 1*4 + 1*5 + 2*3 + 2*4 + 2*5 + 3*4 + 3*5 + 4*5

Visible / Practice Test Cases

Input:
4
56 78 99 10

Output:
19964

Input:
11
5 1 9 6 0 -4 3 15 -6 10 2

Output:
574

Input:
15
-550 552 -981 267 -18 808 -109 513 -782 556 947 -168 -562 143 -895

output:
-2737131

*/
void sumofproduct(int arr[], int size){
    int index=0,sum=0;
    while(index<size){
        for(int a=index;a<size;++a)
        {
        sum+=arr[index]*arr[a+1];
        }
        index++;
        }
        cout<<sum;
}

int main()
{
    int size;
    std::cin >> size;

    // Declare the array with the given size
    int* arr = new int[size];  // Dynamic allocation
    
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    cout<<endl;
    sumofproduct(arr, size);

    return 0;
}
