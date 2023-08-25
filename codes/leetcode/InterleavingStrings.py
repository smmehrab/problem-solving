# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def dfs(self, i, j):
        if i==len(self.s1) and j==len(self.s2):
            return True
        if (i, j) in self.dp:
            return self.dp[(i, j)]

        if i<len(self.s1) and self.s1[i]==self.s3[i+j] and self.dfs(i+1, j):
            return True
        if j<len(self.s2) and self.s2[j]==self.s3[i+j] and self.dfs(i, j+1):
            return True
        self.dp[(i, j)] = False
        return False

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False

        self.s1 = s1
        self.s2 = s2
        self.s3 = s3
        self.dp = {}
        return self.dfs(0, 0)
