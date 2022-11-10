# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = deque()
        for c in s:
            if not stack or stack[-1]!=c:
                stack.append(c)
            elif stack[-1]==c:
                stack.pop()
        set_s = ""
        while stack:
            set_s += stack.pop()
        set_s = set_s[::-1]
        return set_s
