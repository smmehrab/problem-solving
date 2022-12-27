# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maximumBags(self, capacity: list[int], rocks: list[int], additional_rocks: int) -> int:
        n = len(capacity)
        for i in range(n):
            capacity[i] -= rocks[i]
        capacity.sort()

        total = 0
        count = 0
        for needed_rocks in capacity:
            if total + needed_rocks <= additional_rocks:
                total += needed_rocks
                count += 1
            else:
                break

        return count
