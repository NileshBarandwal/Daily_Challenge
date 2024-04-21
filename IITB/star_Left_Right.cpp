#include <iostream>
using namespace std;

void print_pattern(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            if (j <= i || j >= 2 * n - i + 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    print_pattern(n);
    return 0;
}