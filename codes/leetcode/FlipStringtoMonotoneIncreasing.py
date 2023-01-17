# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):

    def _dfs(self, i, zeros):

        if (i, zeros) not in self.dp:

            if zeros and self.s[i] == "0":
                self.dp[(i, zeros)] = min(1+self._dfs(i+1, False), self._dfs(i+1, zeros))

            elif zeros and self.s[i] == "1":
                self.dp[(i, zeros)] = min(1+self._dfs(i+1, zeros), self._dfs(i+1, False))

            elif not zeros and self.s[i] == "1":
                self.dp[(i, zeros)] = self._dfs(i+1, zeros)

            else:
                self.dp[(i, zeros)] = 1+self._dfs(i+1, zeros)

        return self.dp[(i, zeros)]

    def solve_using_dp(self, s):
        self.s = s
        self.dp = {(len(s), True): 0, (len(s), False): 0}
        return self._dfs(0, True)

    def minFlipsMonoIncr(self, s):
        """
        :type s: str
        :rtype: int
        """
        flips = 0
        ones = 0
        for bit in s:
            if bit == "1":
                ones += 1
            else:
                flips = min(flips+1, ones)
        return flips
