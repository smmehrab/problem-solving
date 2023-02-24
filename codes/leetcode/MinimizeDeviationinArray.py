# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:

        max_heap = []
        n = len(nums)
        for i in range(n):
            if nums[i] & 1 == 1:
                nums[i] *= 2
            heapq.heappush(max_heap, (-1)*nums[i])

        min_deviation = float('inf')
        current_min = (-1)*max(max_heap)
        while True:
            current_max = (-1)*heapq.heappop(max_heap)
            deviation = current_max-current_min
            if deviation < min_deviation:
                min_deviation = deviation
            if current_max%2 == 0:
                current_max >>= 1
                current_min = min(current_min, current_max)
                heapq.heappush(max_heap, (-1)*current_max)
            else:
                break
        return min_deviation
