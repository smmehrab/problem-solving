# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def calculate(self, s: str) -> int:
        answer = 0
        number = 0
        sign = 1
        stack = deque()
        for c in s:
            if c.isdigit():
                number = (10*number) + int(c)
            elif c=="+":
                answer += (sign*number)
                number = 0
                sign = 1
            elif c=="-":
                answer += (sign*number)
                number = 0
                sign = -1
            elif c == "(":
                stack.append(answer)
                stack.append(sign)
                answer = 0
                sign = 1
            elif c == ")":
                answer += (sign*number)
                answer *= stack.pop()
                answer += stack.pop()
                number = 0
                sign = 1
        answer += (sign*number)
        return answer