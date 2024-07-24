// 2191. Sort the Jumbled Numbers

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums; // pair of (mapped value, original index)
        
        // Helper function to compute the mapped value of a number
        auto getMappedValue = [&mapping](int num) -> int {
            string original = to_string(num);
            string mapped = "";
            for (char digit : original) {
                mapped += to_string(mapping[digit - '0']);
            }
            return stoi(mapped);
        };
        
        // Create the mappedNums vector with (mapped value, original index)
        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = getMappedValue(nums[i]);
            mappedNums.push_back({mappedValue, i});
        }
        
        // Sort mappedNums based on the mapped value and original index to maintain order
        sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        // Create the result array based on the sorted mappedNums
        vector<int> result;
        for (const auto& p : mappedNums) {
            result.push_back(nums[p.second]);
        }
        
        return result;
    }
};