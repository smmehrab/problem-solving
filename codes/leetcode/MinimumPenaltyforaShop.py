# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        penalty = 0
        min_penalty = 0
        closing_time = 0
        for hour, visit in enumerate(customers):
            penalty += 1 if visit == 'N' else -1
            if penalty < min_penalty:
                min_penalty = penalty
                closing_time = hour + 1
        return closing_time