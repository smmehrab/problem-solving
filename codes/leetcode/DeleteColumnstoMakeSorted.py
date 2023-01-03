# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        n = len(strs)
        m = len(strs[0])
        delete_count = 0
        for i in range(m):
            for j in range(1, n):
                if strs[j][i] < strs[j-1][i]:
                    delete_count += 1
                    break
        return delete_count