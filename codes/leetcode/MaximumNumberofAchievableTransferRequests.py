# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List

class Solution:

    def backtrack(self, index, included):
        if index == self.number_of_requests:
            for i in range(self.n):
                if self.indegree[i] != 0:
                    return
            self.max_included = max(self.max_included, included)
            return

        # exclude
        self.backtrack(index + 1, included)

        # include 
        self.indegree[self.requests[index][0]] -= 1
        self.indegree[self.requests[index][1]] += 1
        self.backtrack(index + 1, included + 1)
        self.indegree[self.requests[index][0]] += 1
        self.indegree[self.requests[index][1]] -= 1

    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        self.n = n
        self.requests = requests
        self.number_of_requests = len(requests)
        self.indegree = [0] * n
        self.max_included = 0
        self.backtrack(0, 0)
        return self.max_included
