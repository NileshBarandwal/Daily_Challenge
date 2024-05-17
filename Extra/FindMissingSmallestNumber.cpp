#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissingSmallest(vector<int>& nums) {
    
    // sort array in begin
    sort(nums.begin(), nums.end());

    int smallestMissing = 1;

    for (int num : nums) {
        // skip negative and 0
        if (num <= 0)
            continue;
        
        // inc smallmissing coz it's already present in array
        if (num == smallestMissing){
            smallestMissing++;
        }else if (num > smallestMissing){
            return num-1;
        }
    }

    return smallestMissing;
}

int main() {
    // Example arrays
    vector<int> arr1 = {-1, 14, 0, 1, 4};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {-1, 2, 3, 4, 5};
    vector<int> arr4 = {0, 1, 3, 4, 5};
    vector<int> arr5 = {0, 1, 2, 3};
    vector<int> arr6 = {-1, -2, -3, -4, 5};
    
    // Test cases
    cout << "Output 1: " << findMissingSmallest(arr1) << endl;
    cout << "Output 2: " << findMissingSmallest(arr2) << endl;
    cout << "Output 3: " << findMissingSmallest(arr3) << endl;
    cout << "Output 4: " << findMissingSmallest(arr4) << endl;
    cout << "Output 5: " << findMissingSmallest(arr5) << endl;
    cout << "Output 6: " << findMissingSmallest(arr6) << endl;

    return 0;
}