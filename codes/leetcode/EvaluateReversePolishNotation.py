# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = deque()
        opcodes = ["+","-","*","/"]
        for token in tokens:
            if token not in opcodes:
                stack.append(int(token))
            else:
                operand2 = stack.pop()
                operand1 = stack.pop()
                result = 0
                if token == "+":
                    result = operand1 + operand2
                elif token == "-":
                    result = operand1 - operand2
                elif token == "*":
                    result = operand1 * operand2
                elif token == "/":
                    result = int(operand1 / operand2)
                stack.append(result)
        return stack.pop()
