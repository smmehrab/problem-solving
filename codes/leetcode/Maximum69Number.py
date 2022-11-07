# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maximum69Number (self, num: int) -> int:
        index = 0
        change_index = -1
        t = num
        while t:
            if (t%10)==6:
                change_index = index
            t //= 10
            index += 1
        
        if change_index != -1:
            num += ((9-6)*10**change_index)

        return num
