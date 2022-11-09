# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Item:

    def __init__(self, price, span):
        self.price = price
        self.span = span

class MonotonicStack():

    """
        Decreasing Monotonic Stack
        Item(price, span)
    """

    def __init__(self):
        self.stack = deque()

    def empty(self):
        return len(self.stack) == 0

    def push(self, item: Item):
        while not self.empty() and self.peek().price <= item.price:
            item.span += self.peek().span
            self.pop()
        self.stack.append(item)
        return item

    def peek(self):
        assert not self.empty()
        return self.stack[-1]

    def pop(self):
        assert not self.empty()
        return self.stack.pop()

class StockSpanner:

    def __init__(self):
        self.monotonic_stack = MonotonicStack()

    def next(self, price: int) -> int:
        item =  self.monotonic_stack.push(Item(price, 1))
        return item.span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)