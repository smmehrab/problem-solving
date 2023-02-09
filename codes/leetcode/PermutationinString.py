# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)

        hash_table = [0] * 26
        base = ord('a')
        for c in s1:
            offset = ord(c) - base
            hash_table[offset] += 1

        left = 0
        right = 0
        match_left = n1
        while right < n2:
            offset = ord(s2[right])-base
            if hash_table[offset] > 0:
                match_left -= 1
            hash_table[offset] -= 1
            right += 1

            if match_left == 0:
                return True
            
            if right - left == n1:
                offset = ord(s2[left]) - base
                if hash_table[offset] >= 0:
                    match_left += 1
                hash_table[offset] += 1
                left += 1

        return False
