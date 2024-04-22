# 2023 - QuestionPaper programming test

## Programming Assignments

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