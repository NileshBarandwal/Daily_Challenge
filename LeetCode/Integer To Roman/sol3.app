class Solution {
public:
    string intToRoman(int num) {
        map<int, string> romanValues = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

// String to build the Roman numeral result
        std::string result;

        // Iterate over the map in descending order (largest to smallest keys)
        for (auto it = romanValues.rbegin(); it != romanValues.rend(); ++it) {
            int key = it->first;  // Current key
            string romanSymbol = it->second;  // Corresponding Roman symbol

            // Determine how many times the symbol should be used
            int count = num / key;  // Get the division result
            if (count > 0) {
                // Use a loop to append the symbol `count` times
                for (int i = 0; i < count; i++) {
                    result.append(romanSymbol);
                }

                // Update the number by subtracting the total key value
                num -= key * count;
            }
        }

        return result;  // Return the final Roman numeral
    }
};