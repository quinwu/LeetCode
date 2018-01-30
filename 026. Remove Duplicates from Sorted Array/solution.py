class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        if len(nums) == 0:
            return index
        flag = nums[0]
        index += 1
        for i in range(len(nums)):
            if nums[i] != flag:
                nums[index] = nums[i]
                flag = nums[i]
                index += 1
        return index
