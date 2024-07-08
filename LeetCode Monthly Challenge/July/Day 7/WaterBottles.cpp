// 1518. Water Bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Using the formula to calculate the total number of bottles you can drink
        return (numBottles * numExchange - 1) / (numExchange - 1);
    }
};