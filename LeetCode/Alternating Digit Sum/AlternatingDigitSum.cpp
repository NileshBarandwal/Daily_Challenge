// 2544. Alternating Digit Sum

class Solution {
public:
    int alternateDigitSum(int n) {
        string itosum = to_string(n);
        int sum=0;
        for(int i=0;i<itosum.length();i++){
            if(i%2 == 0){
                sum+=(itosum[i]-'0');
            }else{
                sum-=(itosum[i]-'0');
            }
        }
        return sum;
    }
};