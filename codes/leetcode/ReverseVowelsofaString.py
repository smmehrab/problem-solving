# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def reverseVowels(self, s: str) -> str:
        n = len(s)
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        letters = list(s)

        left = 0
        right = n-1
        while left<right:
            if s[left] in vowels and s[right] in vowels:
                letters[left], letters[right] = letters[right], letters[left]
                left += 1
                right -= 1
            elif s[left] in vowels:
                right -= 1
            elif s[right] in vowels:
                left += 1
            else:
                left += 1
                right -= 1

        s = ''.join(letters)
        return s
