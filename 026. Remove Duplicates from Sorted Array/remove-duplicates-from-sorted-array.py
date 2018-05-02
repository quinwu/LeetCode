class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        flag = nums[0]
        index = 1
        for i in range(len(nums)):
            if nums[i] != flag:
                nums[index] = nums[i]
                flag = nums[i]
                index += 1
        return index 
                