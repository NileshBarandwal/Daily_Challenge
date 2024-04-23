# 2023 - QuestionPaper programming test

## Programming Assignments


### Q1) SumOfProductsOfAllPair.cpp
```
Q1) For this problem, you will be given n numbers a1, a2, a3, .., an . Write a C++
program to print the sum of the product of all pairs a_i , a_j where i < j (8 Marks)

Input format:
A single number n ( 1 <= n <= 10^6 )
Followed by n numbers a1, a2, ..., an
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
```

### Q2) longestAlternatingRun.cpp
```
Q2) Input a positive decimal number n. Find the maximum run length of a number when
represented in its binary form. A maximum run length in a binary number is defined as maximal
consecutive alternating ones and zeroes. (8 Marks)
For example, 100110101 has runs { 10, 01, 10101 } counting from left to right.
Input format : Input a single number n ( <=10^8 ) in decimal format.
Output format : Output the length of the longest run in the binary representation of n .

Sample Input 1: 309
Sample Output 1: 5

Explanation: The binary representation is: 100110101 . The longest consecutive alternating
sequence of 1’s and 0’s is 10101 .

Sample Input 2: 554
Sample Output 2: 7

Explanation: The binary representation is: 1000101010 . The longest consecutive alternating
sequence of 1’s and 0’s is 0101010 .

Practice/Visible test cases

Input Output

963 2
465 4
661 6
```

### Q3) Phone Price

```
Q3) A new phone is priced at some price, P. Every year, the phone undergoes a sudden price drop given by the formula: priceDrop = (current_price - 12000) 2 / 20000 .

Write a recursive function price() to calculate the price for every year. Accept the number of
years, n , and price, P as input in the main, and pass them to the function. 

Calculate the price after n years, and return the result back to the main. (8 Marks)

Sample input: 1 20000
Sample output: 16800

Sample input: 3 20000
Sample output: 14892.6

Template code, in red, should be made visible to the students.

#include <iostream>
using namespace std;
int price(int years, int current_price) {
//Write your code below this line
return price(years, current_price);
}
int main() {
int years, current_price;
cin >> years >> current_price;
cout << price(years, current_price) << endl;
return 0;
}


Practice/Visible test cases

Input:
3 14750
Output:
13873

Input:
6
15000
Output:
13493

Input:
9
22500
Output:
13503
```

