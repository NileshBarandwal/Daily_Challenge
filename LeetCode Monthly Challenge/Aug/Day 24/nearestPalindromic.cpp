// 564. Find the Closest Palindrome

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long originalNum = stol(n);
        
        // Create possible candidates
        vector<long> candidates;
        
        // 1. Palindrome by mirroring
        string prefix = n.substr(0, (len + 1) / 2);
        candidates.push_back(createPalindrome(prefix, len % 2 == 0));

        // 2. Palindrome by increasing prefix by 1
        long prefixNum = stol(prefix);
        candidates.push_back(createPalindrome(to_string(prefixNum + 1), len % 2 == 0));

        // 3. Palindrome by decreasing prefix by 1
        candidates.push_back(createPalindrome(to_string(prefixNum - 1), len % 2 == 0));

        // 4. Edge cases
        candidates.push_back(pow(10, len - 1) - 1); // e.g., 999, 9999, etc.
        candidates.push_back(pow(10, len) + 1);     // e.g., 1001, 10001, etc.

        // Determine the closest palindrome
        long closestNum = -1;
        long minDiff = LONG_MAX;

        for (long candidate : candidates) {
            if (candidate == originalNum) continue;
            long diff = abs(candidate - originalNum);

            if (diff < minDiff || (diff == minDiff && candidate < closestNum)) {
                minDiff = diff;
                closestNum = candidate;
            }
        }

        return to_string(closestNum);
    }

private:
    // Helper function to create a palindrome by mirroring the prefix
    long createPalindrome(string prefix, bool isEven) {
        string palin = prefix;
        if (!isEven) prefix.pop_back();
        reverse(prefix.begin(), prefix.end());
        palin += prefix;
        return stol(palin);
    }
};
