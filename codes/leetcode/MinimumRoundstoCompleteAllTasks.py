# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import Counter
import math

class Solution:
    def minimumRounds(self, tasks: list[int]) -> int:
        h = Counter(tasks)
        rounds = 0
        for frequency in h.values():
            if frequency == 1:
                return -1
            rounds += math.ceil(frequency/3)
        return rounds