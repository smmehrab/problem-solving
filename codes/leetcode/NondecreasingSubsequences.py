# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def backtrack(self, start, subsequence):
        if start <= self.n and len(subsequence) >= 2:
            self.subsequences.append(subsequence[:])
        visited = {}
        for i in range(start, self.n):
            if len(subsequence) > 0 and self.nums[i] < subsequence[-1]: 
                continue
            if self.nums[i] not in visited: 
                visited[self.nums[i]] = True
                subsequence.append(self.nums[i])
                self.backtrack(i+1, subsequence)
                subsequence.pop()

    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.n = len(nums)
        self.nums = nums
        self.subsequences = []
        self.backtrack(0, [])
        return self.subsequences