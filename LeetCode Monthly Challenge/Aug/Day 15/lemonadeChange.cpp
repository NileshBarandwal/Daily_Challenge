// 860. Lemonade Change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; // counters for $5 and $10 bills

        for (int bill : bills) {
            if (bill == 5) {
                five++; // collect the $5 bill
            } else if (bill == 10) {
                if (five == 0) {
                    return false; // cannot give change
                }
                five--; // give back a $5 bill as change
                ten++; // collect the $10 bill
            } else { // bill is $20
                if (ten > 0 && five > 0) {
                    ten--; // give back a $10 bill
                    five--; // give back a $5 bill
                } else if (five >= 3) {
                    five -= 3; // give back three $5 bills
                } else {
                    return false; // cannot give change
                }
            }
        }
        return true; // successful in providing change to every customer
    }
};
