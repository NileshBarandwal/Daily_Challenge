class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid  # target found
            elif nums[mid] < target:
                left = mid + 1  # target is in the right half
            else:
                right = mid - 1  # target is in the left half
        
        # If target is not found, 'left' is the position where it should be inserted
        return left
