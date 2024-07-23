// 1636. Sort Array by Increasing Frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> incfreq;
        vector<int> result;

        // Populate the frequency map
        for (int num : nums) {
            incfreq[num]++;
        }

        // Create a vector of pairs (frequency, number) and sort it
        vector<pair<int, int>> freqVec;
        for (const auto& pair : incfreq) {
            freqVec.push_back({pair.second, pair.first});
        }

        // Sort by frequency ascending, and by number descending if frequencies are the same
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        // Build the result vector based on sorted frequency and values
        for (const auto& pair : freqVec) {
            for (int i = 0; i < pair.first; ++i) {
                result.push_back(pair.second);
            }
        }

        return result;
    }
};