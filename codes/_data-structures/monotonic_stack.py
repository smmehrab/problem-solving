# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class MonotonicStack():
    """
        MonotonicStack()        --> increasing
        MonotonicStack(False)   --> decreasing
    """

    def __init__(self, increasing=True):
        self.stack = deque()
        self.increasing = increasing if increasing==False else True

    def empty(self):
        return len(self.stack) == 0

    def push(self, item):
        popped = []
        if self.increasing:
            while not self.empty() and item < self.peek():
                popped.append(self.pop())
        else:
            while not self.empty() and item > self.peek():
                popped.append(self.pop())
        self.stack.append(item)
        return popped

    def peek(self):
        assert not self.empty()
        return self.stack[-1]

    def pop(self):
        assert not self.empty()
        return self.stack.pop()

    def __str__(self):
        stack_string = ", ".join(str(element) for element in self.stack)
        return "Monotonic Stack: [{}]".format(stack_string)
