# Problem: Merging Two Sorted Arrays
Given two sorted arrays `nums1` and `nums2` with given lengths `m` and `n`, respectively, the task is to merge these two arrays into a single sorted array. The `nums1` array has extra space to accommodate the elements from `nums2`.

## Intuition
Merging from the back avoids additional space requirements and reduces data movement. Since `nums1` has enough space to contain the merged result, you can use a two-pointer approach to fill `nums1` from the last index backward.

## Approach
- **Pointers**: Initialize three pointers: `i` pointing to the last element of the valid part of `nums1`, `j` pointing to the last element of `nums2`, and `k` pointing to the last available position in `nums1`.
- **Merging**: Compare elements from `nums1` and `nums2` and fill `nums1` from the back, inserting the larger of the two. Decrement `i`, `j`, and `k` as needed.
- **Remaining elements**: If `nums2` still has elements left after the merging loop, insert them into `nums1`. If `nums1` still has elements, they are already in the correct position.

### Detailed Example
- **Input**: 
  - `nums1 = [1, 3, 5, 0, 0, 0]`, `m = 3`
  - `nums2 = [2, 4, 6]`, `n = 3`
- **Output**: `nums1 = [1, 2, 3, 4, 5, 6]`
- **Explanation**:
  1. Initialize `i = 2` (last valid index of `nums1`), `j = 2` (last index of `nums2`), `k = 5` (last index of `nums1`).
  2. **First merging loop**:
     - `nums1[2]` (5) vs `nums2[2]` (6). Insert 6 at `nums1[5]`. Decrement `k`, `j`.
     - `nums1[1]` (3) vs `nums2[1]` (4). Insert 5 at `nums1[4]`. Decrement `k`, `i`.
     - `nums1[1]` (3) vs `nums2[1]` (4). Insert 4 at `nums1[3]`. Decrement `k`, `j`.
     - `nums1[0]` (1) vs `nums2[0]` (2). Insert 3 at `nums1[2]`. Decrement `k`, `i`.
     - Insert 2 at `nums1[1]`. Decrement `k`, `j`.
     - Insert 1 at `nums1[0]`. Decrement `k`, `i`.
  3. **Remaining elements**:
     - No elements remain in `nums1`.
     - `nums2` is exhausted.
  4. The final merged array is `[1, 2, 3, 4, 5, 6]`.

## Complexity
- **Time complexity**: $$O(m + n)$$, where `m` and `n` are the lengths of `nums1` and `nums2`.
- **Space complexity**: $$O(1)$$, as we merge in-place.


# Code
```cpp []
# Code Snippet 1: Optimized Version

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }

        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};
```
```cpp []
# Code Snippet 2 :
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int result[m+n];
        int i=0,j=0,k=0;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                result[k++]=nums1[i++];
            }else{
                result[k++]=nums2[j++];
            }
        }

        while(i<m){
            result[k++]=nums1[i++];
        }

        while(j<n){
            result[k++]=nums2[j++];
        }
            for(int i=0;i<n+m;i++){
                nums1[i]=result[i];
                cout<<nums1[i]<<" ";
            }
    }
};
```
