# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import Counter

class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)
        max_window = k

        count = Counter(answerKey[:k])
        left = 0
        for right in range(k, n):
            count[answerKey[right]] += 1
            while min(count['T'], count['F']) > k: 
                count[answerKey[left]] -= 1
                left += 1
            max_window = max(max_window, right - left + 1)
        return max_window