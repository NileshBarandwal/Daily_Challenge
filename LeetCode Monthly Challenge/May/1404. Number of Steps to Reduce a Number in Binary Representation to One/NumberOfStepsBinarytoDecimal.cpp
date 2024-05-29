class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        while (s != "1") {
            if (s.back() == '0') {
                // If the last character is '0', remove it (equivalent to dividing by 2)
                s.pop_back();
            } else {
                // If the last character is '1', add 1 to the binary number
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            step++;
        }
        return step;
    }
};
