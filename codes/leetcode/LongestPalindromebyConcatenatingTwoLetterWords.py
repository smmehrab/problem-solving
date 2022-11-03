# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import Counter

class Solution:
    def longestPalindrome(self, words: list[str]) -> int:
        word_length = 2
        length = 0
        isOddPalindrome = 0
        frequency = Counter(words)

        for word, count in frequency.items():
            if word[0] == word[1]:
                if count&1 == 0:
                    length += count
                else:
                    length += (count-1)
                    isOddPalindrome = 1

            elif word[0] < word[1]:
                palindrome = word[1] + word[0]
                length += (2 * min(count, frequency[palindrome]))

        length += isOddPalindrome
        length *= word_length
        return length
