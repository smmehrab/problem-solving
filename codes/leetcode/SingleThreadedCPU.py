# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from heapq import heappop, heappush, heapify

class Solution:
    def getOrder(self, tasks: list[list[int]]) -> list[int]:
        # sort tasks
        n = len(tasks)
        tasks = sorted([(task[0], task[1], index) for index, task in enumerate(tasks)])
        # answer
        order = []
        ordered = 0
        # min-heap
        heap = []
        i = 0
        heapify(heap)
        # algorithm
        time = tasks[0][0]
        while ordered < n:
            while i < n and tasks[i][0] <= time:
                heappush(heap, (tasks[i][1], tasks[i][2]))
                i += 1
            if heap:
                processing_time, index = heappop(heap)
                time += processing_time
                order.append(index)
                ordered += 1
            elif i < n:
                time = tasks[i][0]
        return order