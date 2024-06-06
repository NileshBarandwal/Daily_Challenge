// 846. Hand of Straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    // Initialize the result to false
        bool result = false;
        
        // Create a map to count occurrences of each number
        map<int, int> s1;
        for (int i : hand) {
            s1[i]++;
        }
        
        // Vector to store the groups formed or a vector having group of vectors
        //vector<vector<int>> groups;

        // Check if it's possible to form groups of the specified size
        while (!s1.empty()) {
            auto it = s1.begin();
            //vector<int> group;
            int firstNumber = it->first;
            
            // Try to form a group of size groupSize
            for (int i = 0; i < groupSize; ++i) {
                // If the current element is not found in the map, return false
                if (s1.find(firstNumber + i) == s1.end()) {
                    return false;
                }

                // Add the current element to the group
                // group.push_back(it->first);
                // cout<<it->first<<endl;
                
                // Decrement the count of the current element
                if (--s1[firstNumber + i] == 0) {
                    s1.erase(firstNumber + i);  // Remove the element from the map if its count reaches zero
                }
                
                // Move to the next element
                ++it;
            }
            // Store the formed group
            //groups.push_back(group);
        }

        // Print the groups formed
        // for (const auto& grp : groups) {
        //     for (int num : grp) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }
        
        // If all groups are successfully formed, return true
        return true;
    }
};