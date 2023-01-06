# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        costs.sort()
        count = 0
        for cost in costs:
            if coins >= cost:
                coins -= cost
                count += 1
            if coins <= 0:
                break
        return count