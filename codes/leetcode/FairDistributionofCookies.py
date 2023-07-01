# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List

class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n = len(cookies)
        distribution = [0] * k

        def distribute(cookie_index, deprived_children):
            cookie_left = n - cookie_index
            if cookie_left < deprived_children:
                return float('inf')

            if cookie_index == n:
                return max(distribution)

            # backtracking
            answer = float('inf')
            for child_index in range(k):
                deprived_children -= int(distribution[child_index] == 0)
                distribution[child_index] += cookies[cookie_index]

                answer = min(answer, distribute(cookie_index + 1, deprived_children))

                distribution[child_index] -= cookies[cookie_index]
                deprived_children += int(distribution[child_index] == 0)
            return answer

        return distribute(0, k)