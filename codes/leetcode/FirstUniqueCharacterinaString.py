# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1

        answer = float('inf')
        for i, c in enumerate(s):
            if count[ord(c) - ord('a')] == 1:
                answer = min(answer, i)

        if not (answer >= 0 and answer < len(s)):
            answer = -1

        return answer