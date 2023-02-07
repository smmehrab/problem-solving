# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        max_fruits = -1
        current_count = 0
        a = 0
        b = 0
        b_count = 0
        for fruit in fruits:
            if fruit in (a, b):
                current_count += 1
            else:
                current_count = b_count + 1

            if fruit == b:
                b_count += 1
            else:
                a, b = b, fruit
                b_count = 1

            max_fruits = max(max_fruits, current_count)

        return max_fruits