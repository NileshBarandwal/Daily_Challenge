#include <iostream>
using namespace std;

int sumOfUnitDigitsOfFibonacci(int n) {
    if (n <= 0) return 0;

    int a = 0, b = 1;
    int sum = 1; // Initialize sum with 1 to include fib(0)

    for (int i = 2; i <= n; i++) {
        int next = (a + b) % 10;
        sum += next;
        a = b;
        b = next;
    }

    return sum % 10;
}

int main() {
    int N;
    cin >> N;

    // Output the sum of unit digits of Fibonacci numbers
    cout << sumOfUnitDigitsOfFibonacci(N) << endl;

    return 0;
}

// fib(0) = 0 (unit digit: 0)
// fib(1) = 1 (unit digit: 1)
// fib(2) = 1 (unit digit: 1)
// fib(3) = 2 (unit digit: 2)
// fib(4) = 3 (unit digit: 3)
// fib(5) = 5 (unit digit: 5)
// fib(6) = 8 (unit digit: 8)
// fib(7) = 13 (unit digit: 3)
// fib(8) = 21 (unit digit: 1)

// The sum of the unit digits is 0 + 1 + 1 + 2 + 3 + 5 + 8 + 3 + 1 = 24.


