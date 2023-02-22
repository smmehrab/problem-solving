# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low = max(weights)
        high = sum(weights)
        while low<high:
            mid = (low+high)//2
            days_required = 1
            weight_sum = 0
            for weight in weights:
                if weight_sum + weight > mid:
                    days_required += 1
                    weight_sum = 0
                weight_sum += weight
            if days_required > days:
                low = mid + 1
            else: 
                high = mid
        return low
