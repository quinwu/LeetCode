class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        flag = 0
        for index in range(len(nums)):
            if nums[index] != val:
                nums[flag] = nums[index]
                flag += 1
        
        return flag