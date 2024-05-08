#include <vector>

int birthdayCakeCandles(const vector<int> candles) {
    // Initialize the maximum height to the first candle's height
    int maxHeight = candles[0];
    int count = 0;

    // Loop through the candles to find the maximum height and count how many times it occurs
    for (int height : candles) {
        if (height > maxHeight) { // If the current candle is taller
            maxHeight = height;   // Update the maximum height
            count = 1;            // Reset the count
        } else if (height == maxHeight) { // If the current candle is as tall as the maximum
            count++; // Increment the count
        }
    }

    return count; // Return the count of the tallest candles
}
