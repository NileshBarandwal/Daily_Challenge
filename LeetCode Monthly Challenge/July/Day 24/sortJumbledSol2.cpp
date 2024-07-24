// 2191. Sort the Jumbled Numbers

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Create a vector of pairs where each pair is (mapped value, original index)
        vector<pair<int, int>> mappedNums;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int mappedValue = 0;
            int place = 1;

            // Compute the mapped value for the current number
            if (num == 0) {
                mappedValue = mapping[0];
            } else {
                while (num > 0) {
                    int digit = num % 10;
                    mappedValue += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }
            
            mappedNums.push_back(make_pair(mappedValue, i));
        }

        // Sort mappedNums based on the mapped value
        sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        // Create the result array based on the sorted mappedNums
        vector<int> result;
        for (const auto& p : mappedNums) {
            result.push_back(nums[p.second]);
        }

        return result;
    }
};