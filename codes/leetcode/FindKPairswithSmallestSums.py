# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from heapq import heappush, heappop

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        m = len(nums1)
        n = len(nums2)
        visited = set()

        pair = (0, 0)
        minHeap = [(nums1[pair[0]] + nums2[pair[1]], pair)]
        visited.add(pair)

        smallest_pairs = []
        while k > 0 and minHeap:
            priority, (i, j) = heappop(minHeap)
            smallest_pairs.append([nums1[i], nums2[j]])
            if i + 1 < m:
                pair = (i+1, j)
                if pair not in visited:
                    heappush(minHeap, (nums1[i+1] + nums2[j], pair))
                    visited.add(pair)
            if j + 1 < n:
                pair = (i, j+1)
                if pair not in visited:
                    heappush(minHeap, (nums1[i] + nums2[j+1], pair))
                    visited.add(pair)
            k = k - 1
        return smallest_pairs