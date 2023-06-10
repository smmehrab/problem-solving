# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def _sum(self, cnt, end):
        if cnt == 0:
            return 0
        start = max(end - cnt, 0)
        sum1 = end * (end + 1) // 2
        sum2 = start * (start + 1) // 2
        return sum1 - sum2

    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        maxSum -= n
        l, r = 0, maxSum
        while l <= r:
            mid = (l + r) // 2
            left_sum = self._sum(index + 1, mid)
            right_sum = self._sum(n - index - 1, mid - 1)
            if left_sum + right_sum <= maxSum:
                l = mid + 1
            else:
                r = mid - 1
        return l