// 1122. Relative Sort Array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> arr;
        for(int i : arr1){
            arr[i]++;
        }
        // {2:3,3:2,1:1,4:1,6:1,7:1,9:1,19:1}
        vector<int> result;
        for(int i : arr2){
            auto it = arr.find(i);
            if(it != arr.end()){
                while(it->second!=0){
                    result.push_back(it->first);
                    it->second--;
                }
                arr.erase(it); // Remove processed elements from the map
            }
        }

        // Iterate through the map
        for (const auto& pair : arr) {
            int key = pair.first;
            int value = pair.second;

            // Print the key 'value' times
            for (int i = 0; i < value; ++i) {
                result.push_back(key);
            }
        }
        return result;
    }
};