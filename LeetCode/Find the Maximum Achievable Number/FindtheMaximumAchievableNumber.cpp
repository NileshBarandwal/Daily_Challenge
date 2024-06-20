// 2769. Find the Maximum Achievable Number

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int maxnum = max((num - 2*t),(num + 2*t));
        return max(maxnum, num);
        // num=4 , t=1

        // num-1 = 3 , x+1 = 3 then x=2;
        // num-1=3 , x-1=3 then x=4 ;
        // num+1 =5, x-1=5 then x=6;
        // num+1 =5, x+1=5 then x=4;

        // num=3 t=2

        // num-2 = 1 , x+2 = 1 then x=-1;
        // num-2=1 , x-2=1 then x=3 ;
        // num+2 =5, x-2=5 then x=7;
        // num+2 =5, x+2=5 then x=3;

        // num-- , x++;
        // num-- , x--;
        // num++ , x--;
        // num++ , x++;
        
        // num-t = x+t
        // x = num - 2*t
        // num-t = x-t
        // x = num
        // num+t = x-t
        // x = num + 2*t
        // num+t = x+t
        // x = num
    }
};