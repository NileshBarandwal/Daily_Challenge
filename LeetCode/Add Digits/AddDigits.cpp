// 258. Add Digits
// Solution 1

class Solution {
public:
    int addDigits(int num) {
        int count=0;
        while(num>9){
            while(num!=0){
                count+=num%10;
                num = num/10;
            }
            num=count;
            count=0;
        }
        return num;
    }
};