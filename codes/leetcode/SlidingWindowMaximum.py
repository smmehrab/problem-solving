# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class MonotonicQueue():
    """
        MonotonicQueue()        --> increasing
        MonotonicQueue(False)   --> decreasing
    """

    def __init__(self, increasing=True):
        self.queue = deque()
        self.increasing = increasing if increasing==False else True

    def empty(self):
        return len(self.queue) == 0

    def push(self, item):
        popped = []
        if self.increasing:
            while not self.empty() and item < self.queue[-1]:
                popped.append(self.queue.pop())
        else:
            while not self.empty() and item > self.queue[-1]:
                popped.append(self.queue.pop())
        self.queue.append(item)
        return popped

    def peek(self):
        assert not self.empty()
        return self.queue[0]

    def pop(self):
        assert not self.empty()
        return self.queue.popleft()        

    def __str__(self):
        queue_string = ", ".join(str(element) for element in self.queue)
        return "Monotonic Queue: [{}]".format(queue_string)

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        DEBUG = False
        
        max_sliding_window = []
        queue = MonotonicQueue(False)
        
        for right, num in enumerate(nums):
            queue.push(num)
            
            if right<k-1:
                continue
                
            max_sliding_window.append(queue.peek())
            left = right-k+1
            
            if DEBUG:
                print(queue)
                for i in range(left, right+1):
                    print(nums[i]),
                print("")
                print(str(max_sliding_window))
                print("---------------------------------------")
                
            if queue.peek() == nums[left]:
                queue.pop()
            
        return max_sliding_window
