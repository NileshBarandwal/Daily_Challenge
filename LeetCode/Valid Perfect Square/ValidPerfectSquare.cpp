// 367. Valid Perfect Square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        int lb = 1;
        int ub = num;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;  // Avoid overflow
            long square = (long) mid * mid;  // Use long to prevent overflow

            if (square == num) {
                return true;  // Found the perfect square
            } else if (square < num) {
                lb = mid + 1;  // Increase lower bound
            } else {
                ub = mid - 1;  // Decrease upper bound
            }
        }
    
        return false;  // No perfect square found
    }
};