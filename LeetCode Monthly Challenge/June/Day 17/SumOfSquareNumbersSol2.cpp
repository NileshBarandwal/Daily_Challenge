// 633. Sum Of Square Numbers
// Solution 1

class Solution {
public:
    bool judgeSquareSum(int c) {
        int start=0;
        // int end = c*c;
        // More efficient may is to limit range from 0 : c*c to 0:sqrt(c)
        int end = static_cast<int>(sqrt(c)); // explicitly converting the double to an integer as sqrt(c) Returns a Double
        while(start<=end){
            long long sum = static_cast<long long>(start)*start + static_cast<long long>(end)*end;
            if(sum == c){
                return true;
            }else if(sum > c){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }
};