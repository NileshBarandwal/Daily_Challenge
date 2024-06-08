// 258. Add Digits
// Solution 2

class Solution {
public:
    int addDigits(int num) {
        int count=0;
        while(num>9){
            num = (num-1)%9 + 1;
        }
        return num;
    }
};