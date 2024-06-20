// 2769. Find the Maximum Achievable Number
// Optimized version

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return (num + 2*t);
        // Maximum Calculation: The maximum achievable number after t operations is num + 2 * t. 
	// This is because each operation allows a net change of 2 (one for increasing the number and one for increasing num).
        // No Need for Conditional Checks: We do not need to check the minimum bound or 
	// the current value of num since num + 2 * t will always be the largest possible value within the given constraints.

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