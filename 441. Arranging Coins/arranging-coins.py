class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int((math.sqrt(n*2+0.25)-0.5))