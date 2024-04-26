class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { // If needle is empty, the convention is to return 0
            return 0;
        }
        
        // Attempt to find the needle in the haystack
        std::size_t pos = haystack.find(needle);

        // Check if the position is within the bounds of the haystack
        if (pos >= 0 && pos < haystack.size()) {
            return static_cast<int>(pos); // Return the index as an integer
        }

        return -1; // If no valid position found, return -1
    }
};