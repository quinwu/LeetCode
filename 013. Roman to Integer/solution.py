class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapp = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        
        ans = mapp[s[-1]]
        last_strs = s[-1]
        for strs in s[-2::-1]:
            if mapp[strs] < mapp[last_strs]:
                ans = ans - mapp[strs]
            else:
                ans = ans + mapp[strs]
            last_strs = strs
        return ans