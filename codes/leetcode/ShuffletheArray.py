# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def _new_index(self, i):
        return (2*i) if i<self.n else 2*(i-self.n)+1

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        self.n = n
        # -ve value indicates correct placement
        for i in range(2*n):
            j=i
            while nums[i]>=0:
                j = self._new_index(j)
                nums[i], nums[j] = nums[j], -nums[i]
        # revert the minus values
        for i in range(2*n):
            nums[i] *= -1
        return nums