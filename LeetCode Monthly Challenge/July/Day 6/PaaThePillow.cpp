// 2582. Pass the Pillow

class Solution {
public:
    int passThePillow(int n, int time) {
         int position = 1; // starting position
        int direction = 1; // initial direction (1 for forward, -1 for backward)
        
        for (int i = 0; i < time; ++i) {
            position += direction;
            if (position == n || position == 1) {
                direction *= -1; // change direction
            }
        }
        
        return position;
    }
};