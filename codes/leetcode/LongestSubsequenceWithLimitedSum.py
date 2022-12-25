# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def answerQueries(self, nums: list[int], queries: list[int]) -> list[int]:
        n = len(nums)
        nums.sort()

        prefix_sums = []
        prefix_sum = 0
        for num in nums:
            prefix_sum += num
            prefix_sums.append(prefix_sum)

        answer = [0]*len(queries)
        for i, query in enumerate(queries):
            # binary search on prefix_sums
            low = 0
            high = n-1
            while low <= high:
                mid = low + (high - low)//2
                if prefix_sums[mid] == query:
                    print(mid)
                    answer[i] = mid+1
                    break
                elif prefix_sums[mid] < query:
                    answer[i] = mid+1
                    low = mid + 1
                else:
                    high = mid - 1

        return answer