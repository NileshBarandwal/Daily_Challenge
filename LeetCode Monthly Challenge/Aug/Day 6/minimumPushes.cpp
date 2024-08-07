//  3016. Minimum Number of Pushes to Type Word II

class Solution {
public:
    int minimumPushes(std::string word) {
        unordered_map<char, int> freq;
        
        // Count the frequency of each letter in the word
        for (char c : word) {
            freq[c]++;
        }
        
        // Collect the frequencies
        vector<int> frequencies;
        for (auto& pair : freq) {
            frequencies.push_back(pair.second);
        }
        
        // Sort frequencies in descending order
        sort(frequencies.rbegin(), frequencies.rend());
        
        int totalPushes = 0;
        int pushCount = 1;
        int lettersAssigned = 0;
        
        // Iterate through the sorted frequencies
        for (int i = 0; i < frequencies.size(); ++i) {
            totalPushes += frequencies[i] * pushCount;
            lettersAssigned++;
            
            // After every 8 letters (since keys 2-9 are 8 keys), we need to increase the push count
            if (lettersAssigned == 8) {
                lettersAssigned = 0;
                pushCount++;
            }
        }
        
        return totalPushes;
    }
};
