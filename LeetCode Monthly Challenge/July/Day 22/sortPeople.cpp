// 2418. Sort the People

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> people;
        vector<string> name;

        for(int i = 0; i < names.size(); i++) {
            // Option 1: Using pair constructor
            // people.insert(pair<int, string>(heights[i], names[i]));

            // Option 2: Using make_pair
            people.insert(make_pair(heights[i], names[i]));

            // Option 3: Easy and straight foward to directly add key value pair
            // people[heights[i]] = names[i];
        }

        // Printing the map in reverse order
        for (auto it = people.rbegin(); it != people.rend(); ++it) {
            name.push_back(it->second);
        }
        
        return name;
    }
};