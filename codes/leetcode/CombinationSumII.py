# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, start, combination, target):
        if target == 0:
            self.combinations.append(combination)
        else:
            for i in range(start, self.n):
                if i > start and self.candidates[i] == self.candidates[i-1]:
                    continue
                elif self.candidates[i] > target:
                    break
                self._dfs(i+1, combination+[self.candidates[i]], target-self.candidates[i])


    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        self.n = len(candidates)
        self.candidates = sorted(candidates)
        self.combinations = []
        self._dfs(0, [], target)
        return self.combinations