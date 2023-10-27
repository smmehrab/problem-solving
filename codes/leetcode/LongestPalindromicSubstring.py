# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def find_longest_palindrome_at(self, index, s, mode="odd"):
        longest_palindrome_at_index = ""
        longest_palindrome_length_at_index = 0
        left = index
        right = index if mode == "odd" else index+1
        while left>=0 and right<len(s) and s[left] == s[right]:
            if (right-left+1)>longest_palindrome_length_at_index:
                longest_palindrome_at_index = s[left:right+1]
                longest_palindrome_length_at_index = (right-left+1)
            left -= 1
            right += 1
        return longest_palindrome_at_index

    def longestPalindrome(self, s: str) -> str:
        longest_palindrome = ""
        longest_palindrome_len = 0
        for i in range(len(s)):
            longest_odd_palindrome_at_i = self.find_longest_palindrome_at(i, s, "odd")
            longest_even_palindrome_at_i = self.find_longest_palindrome_at(i, s, "even")
            if len(longest_odd_palindrome_at_i) > longest_palindrome_len:
                longest_palindrome = longest_odd_palindrome_at_i
                longest_palindrome_len = len(longest_odd_palindrome_at_i)
            if len(longest_even_palindrome_at_i) > longest_palindrome_len:
                longest_palindrome = longest_even_palindrome_at_i
                longest_palindrome_len = len(longest_even_palindrome_at_i)
        return longest_palindrome