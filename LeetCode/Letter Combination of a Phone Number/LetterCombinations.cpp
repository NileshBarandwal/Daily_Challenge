class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<int, string> phone = {
            {1, "00"},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        // Base case: empty input string
        if (digits.empty()) return result;

        // Initialize result with the first set of letters
        result.push_back("");

        // For each digit in the input string
        for (char digit : digits) {
            int num = digit - '0';
            if (num < 2 || num > 9) continue;  // Skip invalid digits

            // Get the letters corresponding to the current digit
            string letters = phone[num];

            // Store the current size of the result
            int size = result.size();

            // For each existing combination in the result
            for (int i = 0; i < size; ++i) {
                // Append each letter to each existing combination
                for (char letter : letters) {
                    result.push_back(result[i] + letter);
                }
            }

            // Erase combinations that were created in the previous iteration
            result.erase(result.begin(), result.begin() + size);
        }

        return result;
    }
};