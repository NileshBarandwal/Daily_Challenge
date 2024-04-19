# Median of Two Sorted Array

Given two sorted arrays `nums1` and `nums2` of size `m`and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.



## Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

## Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

## Constraints:

`nums1.length == m`

`nums2.length == n`

`0 <= m <= 1000`

`0 <= n <= 1000`

`1 <= m + n <= 2000`

`-106 <= nums1[i], nums2[i] <= 106`

# Intuition

The intuition behind this problem is to find the median of two sorted arrays efficiently. To achieve this, we can use a binary search approach to partition the arrays such that elements to the left of the partition are smaller than or equal to elements on the right side.

# Approach

1. We first ensure that `nums1` is the smaller array, swapping them if necessary.
2. Using binary search, we search for the correct partition point `i` in `nums1`, which divides it into two halves.
3. Based on the partition in `nums1`, we calculate the corresponding partition point `j` in `nums2`.
4. We adjust the search range based on the comparison of elements around the partition points to ensure that elements on the left are smaller than or equal to elements on the right.
5. Once a valid partition is found, we calculate the median based on the elements to the left and right of the partition.

# Complexity

- Time complexity: The time complexity of this approach is `O(log(min(m, n)))`, where m and n are the lengths of the input arrays `nums1` and `nums2`, respectively. This complexity arises from performing binary search on the smaller array and adjusting the partition points based on comparisons with elements in the other array.

- Space complexity: The space complexity of this approach is `O(1)`, as the algorithm uses only a constant amount of extra space for variables, regardless of the input size.