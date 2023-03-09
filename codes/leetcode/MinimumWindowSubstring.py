# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    
    def show_substrings(self, start, end, s):
        i = start
        while i<=end:
            print(s[i]),
            i += 1
        print("")

    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """

        DEBUG = True

        t_frequency = dict()
        for c in t:
            if c in t_frequency:
                t_frequency[c] += 1
            else:
                t_frequency[c] = 1

        s_length = len(s)
        isValid = False
        substring = ""
        window_substring = s

        left = 0
        right = 0
        while right<s_length:
            if s[right] in t_frequency:
                t_frequency[s[right]] -= 1
                if t_frequency[right] > 0:
                    isValid = False
                    right += 1
                elif s[left] not in t_frequency[right]:
                    left += 1

            substring += s[right]

            if isValid:
                if len(substring) < len(window_substring):
                    window_substring = substring
            right += 1

        return window_substring
