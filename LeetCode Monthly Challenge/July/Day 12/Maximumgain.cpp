// 1717. Maximum Score From Removing Substrings

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        // Function to count and remove "ab" or "ba" pairs in a single pass
        auto countAndRemovePairs = [&](string &str, char first, char second, int pointsPerPair) -> int {
            int points = 0;
            string temp;
            for (char c : str) {
                if (!temp.empty() && temp.back() == first && c == second) {
                    temp.pop_back(); // Remove the pair
                    points += pointsPerPair;
                } else {
                    temp.push_back(c);
                }
            }
            str = temp; // Update the original string to the remaining string
            return points;
        };

        // Prioritize higher points first
        if (x > y) {
            totalPoints += countAndRemovePairs(s, 'a', 'b', x); // Remove all "ab" pairs
            totalPoints += countAndRemovePairs(s, 'b', 'a', y); // Then remove all "ba" pairs
        } else {
            totalPoints += countAndRemovePairs(s, 'b', 'a', y); // Remove all "ba" pairs
            totalPoints += countAndRemovePairs(s, 'a', 'b', x); // Then remove all "ab" pairs
        }

        return totalPoints;
    }
};
