// 202. Happy Number

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) { // If n becomes 4, it's guaranteed to fall into a cycle
            int count = 0;
            string s1 = to_string(n);
            for (char ch : s1) {
                count += (ch - '0') * (ch - '0');
            }
            cout<<count<<" ";
            n = count;
        }
        return n == 1;
    }
};