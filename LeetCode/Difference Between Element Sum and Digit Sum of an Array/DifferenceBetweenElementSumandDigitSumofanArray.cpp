// 2535. Difference Between Element Sum and Digit Sum of an Array

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;
        
        for (int num : nums) {
            elementSum += num;
            int currentNum = num;
            while (currentNum != 0) {
                digitSum += currentNum % 10;
                currentNum /= 10;
            }
        }
        
        return abs(elementSum - digitSum);
    }
};