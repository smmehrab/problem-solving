# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        
        n = len(arr)
        
        if n==0:
            return 0
        
        left = 0
        right = 1
        turbulent = 1
        while right<n:
            state = cmp(arr[right-1], arr[right])
            if state == 0:
                left = right
            elif right == n-1 or state * cmp(arr[right], arr[right+1]) != -1:
                turbulent = max(turbulent, right-left+1)
                left = right
            right += 1
    
        return turbulent
        