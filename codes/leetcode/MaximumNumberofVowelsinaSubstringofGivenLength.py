# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        max_vowel_count = -1
        vowel_count = 0
        for i, c in enumerate(s):
            if c in vowels:
                vowel_count += 1
            if i >= k and s[i-k] in vowels:
                vowel_count -= 1
            max_vowel_count = max(max_vowel_count, vowel_count)
        return max_vowel_count